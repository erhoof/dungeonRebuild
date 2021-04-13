//
//  TileComponent.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 16/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "TileComponent.hpp"

TileComponent::TileComponent(int xSrc, int ySrc, int xPos, int yPos, int tileSize, int mapScale, std::string textureID) {
    texture = entity->scene->assets->getTexture(textureID);
    
    position.x = static_cast<float>(xPos);
    position.y = static_cast<float>(yPos);
    
    srcRect.x = xSrc;
    srcRect.y = ySrc;
    srcRect.w = srcRect.h = tileSize;
    
    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = destRect.h = tileSize*mapScale;
}

void TileComponent::render() {
    TextureManager::drawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
}

void TileComponent::update() {
    destRect.x = static_cast<int>(position.x - entity->scene->camera.x);
    destRect.y = static_cast<int>(position.y - entity->scene->camera.y);
}
