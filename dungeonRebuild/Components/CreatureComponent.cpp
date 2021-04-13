//
//  CreatureComponent.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 26/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "CreatureComponent.hpp"

void CreatureComponent::update() {
    if (health > maxHealth)
        health = maxHealth;
    
    if (health <= 0) {
        if (entity->hasComponent<ContainerComponent>())
            entity->getComponent<ContainerComponent>().use();
        
        if (entity->hasComponent<PlayerComponent>()) {
            bool status = entity->getComponent<KeyboardController>().locked;
            
            if (!status) {
                std::time_t t = std::time(0);
                std::tm* now = std::localtime(&t);
                
                LeaderboardManager::Save newScore;
                newScore.hours = now->tm_hour;
                newScore.minutes = now->tm_min;
                newScore.rupies = entity->getComponent<PlayerComponent>().rupies;
                
                strcpy(newScore.name, entity->getComponent<PlayerComponent>().name);
                
                LeaderboardManager::addScore(newScore);
                entity->scene->engine->currentScene = entity->scene->engine->gameScenes["deathScene"];
            }
            
            entity->getComponent<KeyboardController>().locked = true;
        } else
            entity->destroy();
    }
}

void CreatureComponent::render() {
    if (health <= 0)
        if (entity->hasComponent<PlayerComponent>()) {
            srcRect.x = 0;
            srcRect.y = 0;
            srcRect.w = 32;
            srcRect.h = 32;
            
            destRect.x = 0;
            destRect.y = 0;
            destRect.w = 1200;
            destRect.h = 1200;
            
            TextureManager::drawTexture(entity->scene->assets->getTexture("black"), srcRect, destRect, SDL_FLIP_NONE);
            
            TextManager::writeText("GAME OVER.", 420, 400, 50, {255, 255, 255});
        }
}

