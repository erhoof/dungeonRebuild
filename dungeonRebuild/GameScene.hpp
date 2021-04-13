//
//  GameScene.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 11/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <SDL2/SDL.h>

#include "Components/ECS.hpp"

#include "AssetManager.hpp"

#include "GameMap.hpp"
#include "GameWall.hpp"
#include "GameBackground.hpp"

#include "Components/ColliderComponent.hpp"

class GameWall;
class ColliderComponent;
class GameMap;
class GameBackground;
class AssetManager;
class GameEngine;

class GameScene {
    
public:
    enum groupLabels : size_t {
        groupPlayers,
        groupTiles,
        groupEnemies,
        groupPeaceful,
        groupColliders,
        groupProjectiles,
        groupItems,
        groupGUI
    };
    
    const char* name;
    int xSize, ySize,
        xTileSize, yTileSize,
        mapScale, tileSize;
    
    bool endflag = false;
    bool isMenu = false;
    
    GameEngine *engine;
    
    SDL_Rect camera;
    Manager *manager;
    GameMap *map;
    GameBackground *background;
    GameWall *wall;
    std::vector<ColliderComponent *> colliders;
    
    Entity *currentPlayer;
    std::vector<Entity *> *players;
    std::vector<Entity *> *tiles;
    std::vector<Entity *> *enemies;
    std::vector<Entity *> *peaceful;
    std::vector<Entity *> *projectiles;
    std::vector<Entity *> *items;
    std::vector<Entity *> *gui;
    
    AssetManager *assets;
    
    GameScene(const char* nm,
               int ms, int ts, int xs, int ys,
               const char *tilemap, int xts, int yts, GameEngine *mGE);
    ~GameScene();
    
    void init();
    void update();
    void render();
    
    void addAsset(std::string name, const char *dir);
    void addWalls(const char *file);
    void addTiles(const char *file);
    void addBackground(const char *file);
    void addEntity(Entity *entity, groupLabels group);
    Entity& createEntity(groupLabels group);
    void addPlayer(int xPos, int yPos, std::string textureID);
    void endGame();
};

#endif /* GameScene_hpp */
