//
//  GameMap.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 09/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "GameMap.hpp"

GameMap::GameMap(GameScene *scene, std::string textureID, int mapScale, int tileSize, int sizeX, int sizeY, int xTileSize, int yTileSize) {
    this->scene = scene;
    this->textureID = textureID;
    this->mapScale = mapScale;
    this->tileSize = tileSize;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->xTileSize = xTileSize;
    this->yTileSize = yTileSize;
}

void GameMap::loadFile(const char* mapPath) {
    int newTile;
    std::fstream mapFile;
    
    char *fullPath = new char[255];
    strcpy(fullPath, workingDirectory);
    strcat(fullPath, mapPath);
    
    mapFile.open(fullPath);
    
    std::cout << "Loading map...\n";
    std::cout << fullPath << " : "<<  mapFile.is_open() << std::endl;
    
    int xCount, yCount;
    SDL_Rect srcRect, destRect;
    
    for (int i=0; i<sizeY; i++)
        for (int j=0; j<sizeX; j++) {
            mapFile >> newTile;
            
            if (newTile == -1)
                continue;
            
            yCount = newTile/xTileSize;
            xCount = newTile-yCount*xTileSize;
             
            srcRect.x = xCount*tileSize;
            srcRect.y = yCount*tileSize;
            srcRect.w = srcRect.h = tileSize;
             
            destRect.x = j*mapScale - scene->camera.x;
            destRect.y = i*mapScale - scene->camera.y;
            destRect.w = destRect.h = mapScale;
            
            addTile(srcRect.x, srcRect.y, j*tileSize*mapScale, i*tileSize*mapScale);
        }
    
    mapFile.close();
}

void GameMap::addTile(int xSrc, int ySrc, int xPos, int yPos) {
    auto& tile(scene->manager->addEntity(scene));
    //tile.addComponent<TileComponent>(xSrc, ySrc, xPos, yPos, tileSize, mapScale, textureID);
    tile.addComponent<TransformComponent>(xPos, yPos, tileSize, tileSize, mapScale);
    tile.addComponent<ColliderComponent>("tile");
    tile.addGroup(GameScene::groupTiles);
}
