//
//  GameWall.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 03/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef GameWall_hpp
#define GameWall_hpp

#include <iostream>
#include <fstream>

#include "Collision.hpp"
#include "GameScene.hpp"

extern const char* workingDirectory;

class GameScene;

class GameWall {
public:
    GameScene *scene;
    
    int **map;
    
    int mapScale;
    int xSize, ySize;
    int tileSize;
    
    GameWall(GameScene *sc, int mScale, int tSize, int xs, int ys) :
        scene(sc), mapScale(mScale), tileSize(tSize), xSize(xs), ySize(ys) {
        
        map = new int*[ySize];
        for (int i=0; i<ySize; i++) {
            map[i] = new int[xSize];
            for (int j=0; j<xSize; j++)
                map[i][j] = 0;
        }
    }
    
    ~GameWall() {
        for (int i=0; i<ySize; i++) {
            for (int j=0; j<xSize; j++)
                delete &map[i][j];
            delete[] map[i];
        }
    }
    
    void loadFile(const char* filepath) {
        std::fstream mapFile;
        
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, filepath);
        
        mapFile.open(fullPath);
        
        std::cout << "[Map - Wall] " << filepath;
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
                
                if (newTile != -1)
                    map[i][j] = newTile;
            }
        
        mapFile.close();
    }
    
    bool checkDestination (SDL_Rect collider);
    
};

#endif /* GameWall_hpp */
