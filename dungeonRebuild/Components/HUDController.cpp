//
//  HUDController.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "HUDController.hpp"

HUDController::HUDController(std::string textureID) {
    this->textureID = textureID;
}

void HUDController::init() {
    texture = entity->scene->assets->getTexture(textureID);
    transform = &entity->getComponent<TransformComponent>();
}

void HUDController::render() {
    // Life label
    srcRect.x = 39;
    srcRect.y = 0;
    srcRect.w = 44;
    srcRect.h = 7;
    
    destRect.x = 712;
    destRect.y = 60;
    destRect.w = srcRect.w * transform->scale;
    destRect.h = srcRect.h * transform->scale;
    
    TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    
    // Mana
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 16;
    srcRect.h = 42;
    
    destRect.x = 80;
    destRect.y = 72;
    destRect.w = srcRect.w * transform->scale;
    destRect.h = srcRect.h * transform->scale;
    
    TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    
    // Selector
    srcRect.x = 16;
    srcRect.y = 0;
    srcRect.w = 22;
    srcRect.h = 22;
    
    destRect.x = 148;
    destRect.y = 80;
    destRect.w = srcRect.w * transform->scale;
    destRect.h = srcRect.h * transform->scale;
    
    TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    
    // Rupy Icon
    srcRect.x = 16;
    srcRect.y = 22;
    srcRect.w = 8;
    srcRect.h = 8;
    
    destRect.x = 288;
    destRect.y = 60;
    destRect.w = srcRect.w * transform->scale;
    destRect.h = srcRect.h * transform->scale;
    
    TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    
    // Bombs Icon
    srcRect.x = 24;
    srcRect.y = 22;
    srcRect.w = 8;
    srcRect.h = 8;
    
    destRect.x = 400;
    destRect.y = 60;
    destRect.w = srcRect.w * transform->scale;
    destRect.h = srcRect.h * transform->scale;
    
    TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    
    // Arrows Icon
    srcRect.x = 16;
    srcRect.y = 30;
    srcRect.w = 14;
    srcRect.h = 8;
    
    destRect.x = 484;
    destRect.y = 60;
    destRect.w = srcRect.w * transform->scale;
    destRect.h = srcRect.h * transform->scale;
    
    TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    
    //Text info
    TextManager::writeText(entity->getComponent<PlayerComponent>().rupies, 298, 95, 30, {255, 255, 255});
    TextManager::writeText(entity->getComponent<PlayerComponent>().bombs, 412, 95, 30, {255, 255, 255});
    TextManager::writeText(entity->getComponent<PlayerComponent>().arrows, 510, 95, 30, {255, 255, 255});
    
    //Heart containers
    CreatureComponent *cc = &entity->getComponent<CreatureComponent>();
    for (int i=0; i<cc->maxHealth/2; i++) {
        if (i < 10) {
            destRect.x = 644 + (4+28)*i;
            destRect.y = 96;
        } else {
            destRect.x = 644 + (4+28)*(i-10);
            destRect.y = 128;
        }
        
        srcRect.x = 52;
        srcRect.y = 7;
        srcRect.w = 7;
        srcRect.h = 7;
        
        destRect.w = srcRect.w * transform->scale;
        destRect.h = srcRect.h * transform->scale;
        
        TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    }
    
    for (int i=0; i<cc->health; i++) {
        if (i%2) {
            if (i < 20) {
                destRect.x = 644 + (4+28)*(i/2);
                destRect.y = 96;
            } else {
                destRect.x = 644 + (4+28)*(i/2-10);
                destRect.y = 128;
            }
            
            srcRect.x = 38;
            srcRect.y = 7;
        } else {
            if (i < 20) {
                destRect.x = 644 + (4+28)*i/2;
                destRect.y = 96;
            } else {
                destRect.x = 644 + (4+28)*(i/2-10);
                destRect.y = 128;
            }
            
            srcRect.x = 45;
            srcRect.y = 7;
        }
        
        srcRect.w = 7;
        srcRect.h = 7;
            
        destRect.w = srcRect.w * transform->scale;
        destRect.h = srcRect.h * transform->scale;
        
        TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
    }
}
