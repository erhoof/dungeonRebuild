//
//  Game.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 15/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "Game.hpp"

LeaderboardManager::Save *scores;

void Game::spawnAlink(int xPos, int yPos, GameScene *gs) {
    Entity *entity = &gs->createEntity(GameScene::groupEnemies);
    entity->addComponent<TransformComponent>(xPos, yPos, 32, 32, 4);
    entity->addComponent<ColliderComponent>("enemy", 30, 20, 18, 20);
    entity->addComponent<SpriteComponent>("enemy", true);
    entity->addComponent<CreatureComponent>(4);
    entity->addComponent<EnemyAIComponent>(300);
    entity->addComponent<ContainerComponent>();
}

void Game::spawnItem(int xPos, int yPos, std::string name, GameScene *gs) {
    Entity *entity = &gs->createEntity(GameScene::groupItems);
    entity->addComponent<TransformComponent>(xPos, yPos, 16, 16, 4);
    entity->addComponent<ColliderComponent>("item", -32, -32, 32, 32);
    entity->addComponent<SpriteComponent>(name, false);
    entity->addComponent<ItemComponent>(name);
}

void Game::spawnGrass(int xPos, int yPos, GameScene *gs) {
    Entity *entity = &gs->createEntity(GameScene::groupEnemies);
    entity->addComponent<TransformComponent>(xPos, yPos, 16, 16, 4);
    entity->addComponent<ColliderComponent>("item", 0, 0, 16, 16);
    entity->addComponent<SpriteComponent>("grass", false);
    entity->addComponent<CreatureComponent>(1);
    entity->addComponent<ContainerComponent>();
}

void Game::prepareSplash(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
}

void Game::prepareEnterName(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *nameInput = &gs->createEntity(GameScene::groupGUI);
    nameInput->addComponent<TransformComponent>(240, 430, 600, 100, 1);
    nameInput->addComponent<SpriteComponent>("", false);
    nameInput->addComponent<InputFieldComponent>();
    
    Entity *enterMenu = &gs->createEntity(GameScene::groupGUI);
    enterMenu->addComponent<TransformComponent>(270, 780, 500, 80, 1);
    enterMenu->addComponent<SpriteComponent>("", false);
    enterMenu->addComponent<ButtonComponent>("enterMenuButton");
}

void Game::prepareMenuOld(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *newGameButton = &gs->createEntity(GameScene::groupGUI);
    newGameButton->addComponent<TransformComponent>(380, 300, 280, 80, 1);
    newGameButton->addComponent<SpriteComponent>("", false);
    newGameButton->addComponent<ButtonComponent>("newGameButton");
    
    Entity *continueButton = &gs->createEntity(GameScene::groupGUI);
    continueButton->addComponent<TransformComponent>(380, 400, 280, 80, 1);
    continueButton->addComponent<SpriteComponent>("", false);
    continueButton->addComponent<ButtonComponent>("continueButton");
    
    Entity *reselectPlayerButton = &gs->createEntity(GameScene::groupGUI);
    reselectPlayerButton->addComponent<TransformComponent>(360, 500, 300, 80, 1);
    reselectPlayerButton->addComponent<SpriteComponent>("", false);
    reselectPlayerButton->addComponent<ButtonComponent>("reselectPlayerButton");
    
    Entity *tutorialButton = &gs->createEntity(GameScene::groupGUI);
    tutorialButton->addComponent<TransformComponent>(380, 600, 280, 80, 1);
    tutorialButton->addComponent<SpriteComponent>("", false);
    tutorialButton->addComponent<ButtonComponent>("tutorialButton");
    
    Entity *leaderboardButton = &gs->createEntity(GameScene::groupGUI);
    leaderboardButton->addComponent<TransformComponent>(250, 700, 500, 80, 1);
    leaderboardButton->addComponent<SpriteComponent>("", false);
    leaderboardButton->addComponent<ButtonComponent>("leaderboardButton");
    
    Entity *exitButton = &gs->createEntity(GameScene::groupGUI);
    exitButton->addComponent<TransformComponent>(330, 785, 370, 80, 1);
    exitButton->addComponent<SpriteComponent>("", false);
    exitButton->addComponent<ButtonComponent>("exitButton");
}

void Game::prepareMenuNew(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *newGameButton = &gs->createEntity(GameScene::groupGUI);
    newGameButton->addComponent<TransformComponent>(380, 400, 280, 80, 1);
    newGameButton->addComponent<SpriteComponent>("", false);
    newGameButton->addComponent<ButtonComponent>("newGameButton");
    
    Entity *reselectPlayerButton = &gs->createEntity(GameScene::groupGUI);
    reselectPlayerButton->addComponent<TransformComponent>(360, 500, 300, 80, 1);
    reselectPlayerButton->addComponent<SpriteComponent>("", false);
    reselectPlayerButton->addComponent<ButtonComponent>("reselectPlayerButton");
    
    Entity *tutorialButton = &gs->createEntity(GameScene::groupGUI);
    tutorialButton->addComponent<TransformComponent>(380, 600, 280, 80, 1);
    tutorialButton->addComponent<SpriteComponent>("", false);
    tutorialButton->addComponent<ButtonComponent>("tutorialButton");
    
    Entity *leaderboardButton = &gs->createEntity(GameScene::groupGUI);
    leaderboardButton->addComponent<TransformComponent>(250, 700, 500, 80, 1);
    leaderboardButton->addComponent<SpriteComponent>("", false);
    leaderboardButton->addComponent<ButtonComponent>("leaderboardButton");
    
    Entity *exitButton = &gs->createEntity(GameScene::groupGUI);
    exitButton->addComponent<TransformComponent>(330, 785, 370, 80, 1);
    exitButton->addComponent<SpriteComponent>("", false);
    exitButton->addComponent<ButtonComponent>("exitButton");
}

void Game::prepareTutorial(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *backToMenu = &gs->createEntity(GameScene::groupGUI);
    backToMenu->addComponent<TransformComponent>(300, 785, 430, 80, 1);
    backToMenu->addComponent<SpriteComponent>("", false);
    backToMenu->addComponent<ButtonComponent>("backToMenuButton");
}

void Game::addScore(int n, GameScene *gs) {
    std::string line;
    
    Entity *l1 = &gs->createEntity(GameScene::groupGUI);
    
    l1->addComponent<TransformComponent>(100, 200 + n*60, 430, 80, 1);
    line += "Player: ";
    line += scores[n].name;
    line += " [";
    line += std::to_string(scores[n].hours);
    line += ":";
    line += std::to_string(scores[n].minutes);
    line += "] Rupies: ";
    line += std::to_string(scores[n].rupies);
    
    l1->addComponent<LabelComponent>(line);
}

void Game::prepareLeaderboard(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *backToMenu = &gs->createEntity(GameScene::groupGUI);
    backToMenu->addComponent<TransformComponent>(800, 800, 200, 80, 1);
    backToMenu->addComponent<SpriteComponent>("", false);
    backToMenu->addComponent<ButtonComponent>("backToMenuButton");
    
    Entity *print = &gs->createEntity(GameScene::groupGUI);
    print->addComponent<TransformComponent>(40, 800, 150, 80, 1);
    print->addComponent<SpriteComponent>("", false);
    print->addComponent<ButtonComponent>("printButton");
    
    Entity *printCB = &gs->createEntity(GameScene::groupGUI);
    printCB->addComponent<TransformComponent>(230, 800, 150, 80, 1);
    printCB->addComponent<SpriteComponent>("", false);
    printCB->addComponent<ButtonComponent>("clearButton");
    
    scores = LeaderboardManager::loadFile("leaders");
    
    if (scores[0].name[0] != 0)
        for (int i=0; i<10; i++)
            if (scores[i].name[0] != 0)
                addScore(i, gs);
}

void Game::preparePause(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *backToGame = &gs->createEntity(GameScene::groupGUI);
    backToGame->addComponent<TransformComponent>(340, 600, 320, 80, 1);
    backToGame->addComponent<SpriteComponent>("", false);
    backToGame->addComponent<ButtonComponent>("backToGameButton");
    
    Entity *saveQuit = &gs->createEntity(GameScene::groupGUI);
    saveQuit->addComponent<TransformComponent>(170, 690, 700, 80, 1);
    saveQuit->addComponent<SpriteComponent>("", false);
    saveQuit->addComponent<ButtonComponent>("saveAndMenuButton");
    
    Entity *quit = &gs->createEntity(GameScene::groupGUI);
    quit->addComponent<TransformComponent>(320, 780, 380, 80, 1);
    quit->addComponent<SpriteComponent>("", false);
    quit->addComponent<ButtonComponent>("menuButton");
}

void Game::prepareDeath(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *backToMenu = &gs->createEntity(GameScene::groupGUI);
    backToMenu->addComponent<TransformComponent>(300, 785, 430, 80, 1);
    backToMenu->addComponent<SpriteComponent>("", false);
    backToMenu->addComponent<ButtonComponent>("reselectPlayerButton");
}

void Game::prepareEnd(GameScene *gs) {
    Entity *background = &gs->createEntity(GameScene::groupTiles);
    background->addComponent<TransformComponent>(0, 0, 1024, 896, 1);
    background->addComponent<SpriteComponent>("background", false);
    
    Entity *backToMenu = &gs->createEntity(GameScene::groupGUI);
    backToMenu->addComponent<TransformComponent>(300, 785, 430, 80, 1);
    backToMenu->addComponent<SpriteComponent>("", false);
    backToMenu->addComponent<ButtonComponent>("reselectPlayerButton");
}
