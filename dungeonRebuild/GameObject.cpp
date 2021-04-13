//
//  GameObject.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 09/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject(const char *textureFile, int xPos, int yPos) {
    texture = TextureManager::loadTexture(textureFile);
    
    this->xPos = xPos;
    this->yPos = yPos;
}

void GameObject::update() {
    srcRect.h = 8;
    srcRect.w = 8;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xPos;
    destRect.y = yPos;
    destRect.h = srcRect.h * 4;
    destRect.w = srcRect.w * 4;
}

void GameObject::render() {
    SDL_RenderCopy(GameEngine::renderer, texture, &srcRect, &destRect);
}
