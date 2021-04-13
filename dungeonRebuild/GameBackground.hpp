//
//  GameBackground.hpp
//  Dungeon Rebuild
//
//  Created by Pavel Bibichenko on 24/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef GameBackground_hpp
#define GameBackground_hpp

extern const char* workingDirectory;

#include <iostream>
#include <fstream>
#include <cstring>

#include "GameEngine.hpp"
#include "Game.hpp"

class GameBackground {
public:
    GameScene *scene;
    
    int **map;
    
    std::string assetName;
    SDL_Texture *texture;
    
    int mapScale;
    int xSize, ySize;
    
    int tileSize;
    int xTileSize, yTileSize;
    
    GameBackground(GameScene *sc, std::string aName, int mScale, int tSize, int xs, int ys, int txs, int yxs);
    
    ~GameBackground() {
        for (int i=0; i<ySize; i++) {
            for (int j=0; j<xSize; j++)
                delete &map[i][j];
            delete[] map[i];
        }
    }
    
    void loadFile(const char* filepath);
    
    void render();
};

#endif /* GameBackground_hpp */
