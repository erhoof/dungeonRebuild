//
//  SaveManager.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef SaveManager_hpp
#define SaveManager_hpp

#include <iostream>
#include <fstream>

#include "GameEngine.hpp"

extern const char* workingDirectory;

class SaveManager {
public:
    struct Save {
        float xPos, yPos;
        int hp, maxHp,
            rupies, arrows, bombs;
        bool isLoaded;
        bool isFinished;
    };
    
    static bool saveExists;
    
    static Save createFile(const char* name) {
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/");
        strcat(fullPath, name);
        strcat(fullPath, ".sav");
        
        Save newSave;
        newSave.xPos = 250;
        newSave.yPos = 550;
        newSave.hp = 10;
        newSave.maxHp = 16;
        newSave.rupies = 0;
        newSave.arrows = 10;
        newSave.bombs = 0;
        
        newSave.isLoaded = false;
        newSave.isFinished = false;
        
        std::cout << "[SaveManager] Create save file " << name << std::endl;
        
        std::ofstream saveFile;
        saveFile.open(fullPath, std::ios::binary);
        saveFile.write((char *)&newSave, sizeof(newSave));
        
        saveFile.close();
        
        return newSave;
    }
    
    static Save loadFile(const char* name) {
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/");
        strcat(fullPath, name);
        strcat(fullPath, ".sav");
        
        Save loadedSave;
        std::cout << "[SaveManager] Loading save file " << name << std::endl;
        
        std::ifstream saveFile;
        saveFile.open(fullPath, std::ios::binary);
        
        if (saveFile.is_open()) {
            saveFile.read((char *)&loadedSave, sizeof(loadedSave));
            
            loadedSave.isLoaded = true;
            
            saveFile.close();
        } else {
            loadedSave.isLoaded = false;
            
            createFile(name);
            saveFile.open(fullPath, std::ios::binary);
            
            saveFile.read((char *)&loadedSave, sizeof(loadedSave));
            
            saveFile.close();
        }
        
        return loadedSave;
    }
    
    static void saveFile(Entity *player);
};

#endif /* SaveManager_hpp */
