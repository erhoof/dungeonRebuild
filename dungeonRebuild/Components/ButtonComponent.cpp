//
//  ButtonComponent.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 23/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "ButtonComponent.hpp"

void ButtonComponent::update() {
    if (GameEngine::event.type == SDL_MOUSEBUTTONDOWN) {
        if (GameEngine::event.motion.x >= transform->position.x && GameEngine::event.motion.x <= (transform->position.x+transform->width)
            && GameEngine::event.motion.y >= transform->position.y && GameEngine::event.motion.y <= (transform->position.y+transform->height)) {
            
            if (tag == "exitButton") {
                std::cout << "Quitting game...\n";
                GameEngine::runningStatus = false;
            } else if (tag == "enterMenuButton") {
                Entity *inputField = nullptr;
                
                for (auto& i: *entity->scene->gui) {
                    if (i->hasComponent<InputFieldComponent>()) {
                        inputField = i;
                        break;
                    }
                }
                
                const char* gameFileName = inputField->getComponent<InputFieldComponent>().buf;
                
                if (gameFileName[0]) {
                    SaveManager::Save curSave = SaveManager::loadFile(gameFileName);
                    
                    Entity *player = entity->scene->engine->gameScenes["mainScene"]->currentPlayer;
                    
                    player->getComponent<TransformComponent>().position.x = curSave.xPos;
                    player->getComponent<TransformComponent>().position.y = curSave.yPos;
                    
                    player->getComponent<CreatureComponent>().health = curSave.hp;
                    player->getComponent<CreatureComponent>().maxHealth = curSave.maxHp;
                    
                    strcpy(player->getComponent<PlayerComponent>().name, gameFileName);
                    player->getComponent<PlayerComponent>().arrows = curSave.arrows;
                    player->getComponent<PlayerComponent>().rupies = curSave.rupies;
                    player->getComponent<PlayerComponent>().bombs = curSave.bombs;
                    
                    if (curSave.isLoaded) {
                        SaveManager::saveExists = true;
                        
                        entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneOld"];
                    } else {
                        SaveManager::saveExists = false;
                        
                        entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneNew"];
                    }
                }
            } else if (tag == "newGameButton") {
                SaveManager::Save curSave = SaveManager::createFile(entity->scene->engine->gameScenes["mainScene"]->currentPlayer->getComponent<PlayerComponent>().name);
                
                Entity *player = entity->scene->engine->gameScenes["mainScene"]->currentPlayer;
                
                player->getComponent<TransformComponent>().position.x = curSave.xPos;
                player->getComponent<TransformComponent>().position.y = curSave.yPos;
                
                player->getComponent<CreatureComponent>().health = curSave.hp;
                player->getComponent<CreatureComponent>().maxHealth = curSave.maxHp;
                
                strcpy(player->getComponent<PlayerComponent>().name, entity->scene->engine->gameScenes["mainScene"]->currentPlayer->getComponent<PlayerComponent>().name);
                player->getComponent<PlayerComponent>().arrows = curSave.arrows;
                player->getComponent<PlayerComponent>().rupies = curSave.rupies;
                player->getComponent<PlayerComponent>().bombs = curSave.bombs;
                
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["mainScene"];
            } else if (tag == "continueButton") {
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["mainScene"];
            } else if (tag == "reselectPlayerButton") {
                SaveManager::saveExists = false;
                
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["enterNameScene"];
            } else if (tag == "tutorialButton") {
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["tutorialScene"];
            } else if (tag == "backToMenuButton") {
                if (SaveManager::saveExists)
                    entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneOld"];
                else
                    entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneNew"];
            } else if (tag == "leaderboardButton") {
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["statsScene"];
            } else if (tag == "printButton") {
                LeaderboardManager::print();
            } else if (tag == "clearButton") {
                LeaderboardManager::createFile("leaders");
                LeaderboardManager::loadFile("leaders");
                
                if (SaveManager::saveExists)
                    entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneOld"];
                else
                    entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneNew"];
            } else if (tag == "backToGameButton") {
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["mainScene"];
            } else if (tag == "saveAndMenuButton") {
                SaveManager::saveFile(entity);
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneOld"];
            } else if (tag == "menuButton") {
                SaveManager::Save curSave = SaveManager::loadFile(entity->scene->engine->gameScenes["mainScene"]->currentPlayer->getComponent<PlayerComponent>().name);
                
                Entity *player = entity->scene->engine->gameScenes["mainScene"]->currentPlayer;
                
                player->getComponent<TransformComponent>().position.x = curSave.xPos;
                player->getComponent<TransformComponent>().position.y = curSave.yPos;
                
                player->getComponent<CreatureComponent>().health = curSave.hp;
                player->getComponent<CreatureComponent>().maxHealth = curSave.maxHp;
                
                strcpy(player->getComponent<PlayerComponent>().name, entity->scene->engine->gameScenes["mainScene"]->currentPlayer->getComponent<PlayerComponent>().name);
                player->getComponent<PlayerComponent>().arrows = curSave.arrows;
                player->getComponent<PlayerComponent>().rupies = curSave.rupies;
                player->getComponent<PlayerComponent>().bombs = curSave.bombs;
                
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["menuSceneOld"];
            }
        }
    }
}
