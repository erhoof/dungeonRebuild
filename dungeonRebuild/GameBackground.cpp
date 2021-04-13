//
//  GameBackground.cpp
//  Dungeon Rebuild
//
//  Created by Pavel Bibichenko on 24/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "GameBackground.hpp"

GameBackground::GameBackground(GameScene *sc, std::string aName, int mScale, int tSize, int xs, int ys, int txs, int yxs) :
scene(sc), assetName(aName), mapScale(mScale), tileSize(tSize), xSize(xs), ySize(ys), xTileSize(txs), yTileSize(yxs) {
    map = new int*[ySize];
    for (int i=0; i<ySize; i++) {
        map[i] = new int[xSize];
        for (int j=0; j<xSize; j++)
            map[i][j] = 0;
    }
    
    texture = scene->assets->getTexture(assetName);
}

void GameBackground::render() {
    //    tile.addComponent<TileComponent>(xSrc, ySrc, xPos, yPos, tileSize, mapScale, textureID);
    int xCount, yCount, element, scale = tileSize*mapScale;
    SDL_Rect srcRect, destRect;
    
    for (int i=0; i<ySize; i++)
        for (int j=0; j<xSize; j++) {
            element = map[i][j];
            yCount = element/xTileSize;
            xCount = element-yCount*xTileSize;
            
            srcRect.x = xCount*tileSize;
            srcRect.y = yCount*tileSize;
            srcRect.w = srcRect.h = tileSize;
            
            destRect.x = j*scale - scene->camera.x;
            destRect.y = i*scale - scene->camera.y;
            destRect.w = destRect.h = scale;
            
            TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
        }
}

void GameBackground::loadFile(const char* filepath) {
    std::fstream mapFile;
    
    char *fullPath = new char[255];
    strcpy(fullPath, workingDirectory);
    strcat(fullPath, filepath);
    
    mapFile.open(fullPath);
    
    std::cout << "[Map - Background] " << filepath;
    if (mapFile.is_open())
        std::cout << " - [Done]\n";
    else
        std::cout << " - [Error]\n";
    
    if (mapFile.is_open() == 0)
        return;
    
    int newTile;
    
    for (int i=0; i<ySize; i++)
        for (int j=0; j<xSize; j++) {
            mapFile >> newTile;
            
            if (newTile == 5) {
                Game::spawnGrass(j*4*8, i*4*8, scene);
                continue;
            }
            
            if (newTile == 6 || newTile == 45 || newTile == 46)
                continue;
            
            if (newTile != -1)
                map[i][j] = newTile;
        }
    
    mapFile.close();
    }
