//
//  GameMap.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 09/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef GameMap_hpp
#define GameMap_hpp

#include "GameEngine.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include <fstream>

class GameMap {
    const char* filepath;
    std::string textureID;
    
    int mapScale;
    int tileSize;
    
    int sizeX, sizeY;
    int xTileSize, yTileSize;
    
public:
    GameScene *scene;
    
    GameMap(GameScene *scene, std::string textureID, int mapScale, int tileSize, int sizeX, int sizeY, int xTileSize, int yTileSize);
    
    void loadFile(const char* filepath);
    void addTile(int xSrc, int ySrc, int xPos, int yPos);
};

#endif /* GameMap_hpp */
