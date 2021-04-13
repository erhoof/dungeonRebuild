//
//  ColliderComponent.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 15/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "ColliderComponent.hpp"

ColliderComponent::ColliderComponent(std::string t) : tag(t) {}

ColliderComponent::ColliderComponent(std::string t, int w, int h) : tag(t) {
    collider.w = w;
    collider.h = h;

    initWithSizes = true;
}

ColliderComponent::ColliderComponent(std::string t, int x, int y, int w, int h) : tag(t) {
    offsetX = x;
    offsetY = y;
    collider.w = w;
    collider.h = h;
    
    initWithSizes = true;
}

void ColliderComponent::update() {
    collider.x = static_cast<int>(transform->position.x) + offsetX;
    collider.y = static_cast<int>(transform->position.y) + offsetY;
    
    //TextureManager::drawTexture(texture, srcRect, destRect, spriteFlip);
}

void ColliderComponent::render() {
    /* SDL_Rect srcRect, destRect;
    
    srcRect.x = srcRect.y = 0;
    srcRect.w = collider.w;
    srcRect.h = collider.h;
    
    destRect.x = collider.x - entity->scene->camera.x;
    destRect.y = collider.y - entity->scene->camera.y;
    destRect.w = collider.w * 4;
    destRect.h = collider.h * 4;
    
    TextureManager::drawTexture(entity->scene->assets->getTexture("black"), srcRect, destRect, SDL_FLIP_NONE); */
}

void ColliderComponent::init() {
    if (!entity->hasComponent<TransformComponent>())
        entity->addComponent<TransformComponent>();
    
    transform = &entity->getComponent<TransformComponent>();
    
    if (!initWithSizes) {
        collider.w = transform->width;
        collider.h = transform->height;
    }
    
    entity->scene->colliders.push_back(this);
}
