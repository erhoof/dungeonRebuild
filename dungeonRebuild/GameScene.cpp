//
//  GameScene.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 11/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "GameScene.hpp"

GameScene::GameScene(const char* nm,
                    int ms, int ts, int xs, int ys,
                    const char *tilemap, int xts, int yts, GameEngine *mGE) :
                        name(nm), mapScale(ms), tileSize(ts),
                        xSize(xs), ySize(ys), xTileSize(xts), yTileSize(yts), engine(mGE) {
    manager = new Manager();
    
    currentPlayer = &manager->addEntity(this);
    currentPlayer->addGroup(groupPlayers);
    
    players = &manager->getGroup(groupPlayers);
    tiles = &manager->getGroup(groupTiles);
    enemies = &manager->getGroup(groupEnemies);
    peaceful = &manager->getGroup(groupPeaceful);
    projectiles = &manager->getGroup(groupProjectiles);
    items = &manager->getGroup(groupItems);
    gui = &manager->getGroup(groupGUI);
    
    assets = new AssetManager(manager, this);
    assets->addTexture("tilemap", tilemap);
    
    camera.w = 8*4*80/2+1024/4;
    camera.h = 8*4*80/2+896/4 + 32*4+8*4;
}

GameScene::~GameScene() {
    delete manager;
    delete map;
    delete background;
    delete wall;
    
    delete currentPlayer;
    
    delete assets;
}

void GameScene::init() {
    wall = new GameWall(this, mapScale, tileSize, xSize, ySize);
    map = new GameMap(this, "tilemap", mapScale, tileSize, xSize, ySize, xTileSize, yTileSize);
    background = new GameBackground(this, "tilemap", mapScale, tileSize, xSize, ySize, xTileSize, yTileSize);
}

void GameScene::update() {
    if (engine->currentScene == engine->gameScenes["splashScene"] && SDL_GetTicks()>2500)
        engine->currentScene = engine->gameScenes["enterNameScene"];
    
    Vector2D playerPosition = currentPlayer->getComponent<TransformComponent>().position;
    
    TransformComponent *transform = &currentPlayer->getComponent<TransformComponent>();
    
    manager->refresh();
    manager->update();
    
    if (wall->checkDestination(currentPlayer->getComponent<ColliderComponent>().collider)) {
        
        transform->position.x -= transform->velocity.x * transform->speed;
        transform->position.y -= transform->velocity.y * transform->speed;
        
        transform->velocity.zero();
    }
    
    for (auto& e: *enemies) {
        transform = &e->getComponent<TransformComponent>();
        
        if (wall->checkDestination(e->getComponent<ColliderComponent>().collider)) {
            
            transform->position.x -= transform->velocity.x * transform->speed;
            transform->position.y -= transform->velocity.y * transform->speed;
            
            transform->velocity.zero();
        }
    }
    
    for (auto& p: *projectiles) {
        if (Collision::AABB(currentPlayer->getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider)) {
            if (p->getComponent<ProjectileComponent>().tag == "slash") {
                currentPlayer->getComponent<CreatureComponent>().health -= 1;
                //currentPlayer->getComponent<TransformComponent>().velocity = p->getComponent<TransformComponent>().velocity;
                p->destroy();
            }
        }
        
        for (auto& e: *enemies) {
            if (Collision::AABB(e->getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider)) {
                if (p->getComponent<ProjectileComponent>().tag == "pSlash") {
                    e->getComponent<CreatureComponent>().health -= 1;
                    //e->getComponent<TransformComponent>().velocity = p->getComponent<TransformComponent>().velocity;
                    p->destroy();
                }
            }
        }
    }
    
    for (auto& i: *items) {
        if (Collision::AABB(currentPlayer->getComponent<ColliderComponent>().collider, i->getComponent<ColliderComponent>().collider)) {
            if (i->getComponent<ItemComponent>().tag == "heart")
                currentPlayer->getComponent<CreatureComponent>().health++;
            
            if (i->getComponent<ItemComponent>().tag == "heartc")
                currentPlayer->getComponent<CreatureComponent>().maxHealth += 2;
            
            if (i->getComponent<ItemComponent>().tag == "r1")
                currentPlayer->getComponent<PlayerComponent>().rupies += 1;
            
            if (i->getComponent<ItemComponent>().tag == "r5")
                currentPlayer->getComponent<PlayerComponent>().rupies += 5;
            
            if (i->getComponent<ItemComponent>().tag == "r10")
                currentPlayer->getComponent<PlayerComponent>().rupies += 10;
            
            if (i->getComponent<ItemComponent>().tag == "arrow")
                currentPlayer->getComponent<PlayerComponent>().arrows++;
            
            if (i->getComponent<ItemComponent>().tag == "endgame") {
                endflag = true;
                endGame();
            }
            
            i->destroy();
        }
    }
    
    camera.x = playerPosition.x - (1024/2) + 16*4;
    camera.y = playerPosition.y - (896/2) + 16*4;
    
    if (camera.x < 0)
        camera.x = 0;
    
    if (camera.y < 0)
        camera.y = 0;
    
    if (camera.x > camera.w)
        camera.x = camera.w;
    
    if (camera.y > camera.h)
        camera.y = camera.h;
}

void GameScene::render() {
    background->render();

    for (auto& t : *tiles)
        t->render();

    for (auto& i: *items)
        i->render();

    for (auto& t : *enemies)
        t->render();

    for (auto& t : *players)
        t->render();

    for (auto& p: *projectiles)
        p->render();
    
    for (auto& g: *gui)
        g->render();
    
    if (endflag) {
        SDL_Rect srcRect, destRect;
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = 32;
        srcRect.h = 32;
        
        destRect.x = 0;
        destRect.y = 0;
        destRect.w = 1200;
        destRect.h = 1200;
        
        TextureManager::drawTexture(assets->getTexture("black"), srcRect, destRect, SDL_FLIP_NONE);
        
        TextManager::writeText("Your jorney is complete!", 300, 400, 50, {255, 255, 255});
        
        endflag = false;
        
        LeaderboardManager::Save newScore;
        newScore.hours = -1;
        newScore.minutes = 0;
        newScore.rupies = 1000;
        strcpy(newScore.name, currentPlayer->getComponent<PlayerComponent>().name);
        
        LeaderboardManager::addScore(newScore);
        
        for (auto& g: *engine->gameScenes["statsScene"]->gui)
            g->destroy();
        
        std::cout << "Replerairing statsScene\n";
        Game::prepareLeaderboard(engine->gameScenes["statsScene"]);
        
        engine->currentScene = engine->gameScenes["endScene"];
    }
}

void GameScene::addAsset(std::string name, const char *file) {
    assets->addTexture(name, file);
}

void GameScene::addWalls(const char *file) {
    wall->loadFile(file);
}

void GameScene::addTiles(const char *file) {
    map->loadFile(file);
}

void GameScene::addBackground(const char *file) {
    background->loadFile(file);
}

void GameScene::addEntity(Entity *entity, groupLabels group) {
    manager->addEntity(entity, group);
}

Entity& GameScene::createEntity(groupLabels group) {
    return manager->addEntity(this, group);
}

void GameScene::addPlayer(int xPos, int yPos, std::string textureID) {
    currentPlayer->addComponent<TransformComponent>(xPos, yPos, 32, 32, 4);
    currentPlayer->addComponent<ColliderComponent>("player", 30, 20, 18, 20);
    currentPlayer->addComponent<PlayerComponent>();
    currentPlayer->addComponent<CreatureComponent>(40);
    if (!isMenu) {
        currentPlayer->addComponent<SpriteComponent>(textureID, true);
        currentPlayer->addComponent<KeyboardController>();
        currentPlayer->addComponent<HUDController>("hud");
    }
}

void GameScene::endGame() {
    bool status = currentPlayer->getComponent<KeyboardController>().locked;
    
    if (!status) {
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/leaderboard.ini");
        char *ftmp = new char[255];
        strcpy(ftmp, workingDirectory);
        strcat(ftmp, "/Resources/Assets/Settings/leaderboard.tmp");
        
        std::ifstream file(fullPath);
        std::fstream fileN(ftmp, std::ios_base::app | std::ios_base::in | std::ios_base::out);
        
        std::time_t t = std::time(0);   // get time now
        std::tm* now = std::localtime(&t);
        
        std::string out;
        out = "(";
        out += std::to_string(now->tm_hour);
        out += ":";
        out += std::to_string(now->tm_min);
        out += ") End.";
        out += "\n";
        
        fileN << out;
        
        std::string tmp;
        while(getline(file, tmp)) {
            fileN << tmp;
            fileN << "\n";
        }
        
        file.close();
        fileN.close();
        
        rename(ftmp, fullPath);
    }
    
    currentPlayer->getComponent<KeyboardController>().locked = true;
}
