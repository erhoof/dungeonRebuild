//
//  SaveManager.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "SaveManager.hpp"

bool SaveManager::saveExists;

void SaveManager::saveFile(Entity *player) {
    char *fullPath = new char[255];
    strcpy(fullPath, workingDirectory);
    strcat(fullPath, "/Resources/Assets/Settings/");
    strcat(fullPath, player->scene->currentPlayer->getComponent<PlayerComponent>().name);
    strcat(fullPath, ".sav");
    
    Save newSave;
    newSave.xPos = player->scene->currentPlayer->getComponent<TransformComponent>().position.x;
    newSave.yPos = player->scene->currentPlayer->getComponent<TransformComponent>().position.y;
    newSave.hp = player->scene->currentPlayer->getComponent<CreatureComponent>().health;
    newSave.maxHp = player->scene->currentPlayer->getComponent<CreatureComponent>().maxHealth;
    newSave.rupies = player->scene->currentPlayer->getComponent<PlayerComponent>().rupies;
    newSave.arrows = player->scene->currentPlayer->getComponent<PlayerComponent>().arrows;
    newSave.bombs = player->scene->currentPlayer->getComponent<PlayerComponent>().bombs;
    
    std::ofstream saveFile;
    saveFile.open(fullPath, std::ios::binary);
    saveFile.write((char *)(&newSave), sizeof(Save));
    
    saveFile.close();
}
