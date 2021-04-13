//
//  SpriteComponent.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 14/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(std::string textureID) {
    this->textureID = textureID;
}

SpriteComponent::SpriteComponent(std::string textureID, double angle) {
    this->textureID = textureID;
    this->angle = angle;
}


SpriteComponent::SpriteComponent(std::string textureID, bool isAnimated) {
    this->textureID = textureID;
    
    animated = isAnimated;
    
    Animation idleD = Animation(0, 1, 100);
    Animation idleL = Animation(1, 1, 100);
    Animation idleU = Animation(2, 1, 100);

    Animation walkD = Animation(3, 8, 70);
    Animation walkL = Animation(4, 8, 70);
    Animation walkU = Animation(5, 8, 70);
    
    Animation attackD = Animation(6, 6, 70);
    Animation attackL = Animation(7, 5, 70);
    Animation attackU = Animation(8, 5, 70);
    
    animations.emplace("IdleD", idleD);
    animations.emplace("IdleL", idleL);
    animations.emplace("IdleU", idleU);

    animations.emplace("WalkD", walkD);
    animations.emplace("WalkL", walkL);
    animations.emplace("WalkU", walkU);
    
    animations.emplace("AttackD", attackD);
    animations.emplace("AttackL", attackL);
    animations.emplace("AttackU", attackU);
    
    play("IdleD");
}

void SpriteComponent::init() {
    transform = &entity->getComponent<TransformComponent>();
    
    srcRect.x = srcRect.y = 0;
    srcRect.w = transform->width;
    srcRect.h = transform->height;
    
    setTexture(textureID);
}

void SpriteComponent::render() {
    //TextureManager::drawTexture(texture, srcRect, destRect, spriteFlip);
    TextureManager::drawTextureRotated(texture, srcRect, destRect, spriteFlip, angle);
}

void SpriteComponent::update() {
    if (animated)
        srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    
    switch (actIndex) {
        case 0:
            switch (transform->side) {
                case 0:
                    play("IdleD");
                    break;
                case 1:
                    play("IdleL");
                    spriteFlip = SDL_FLIP_NONE;
                    break;
                case 2:
                    play("IdleU");
                    break;
                case 3:
                    play("IdleL");
                    spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
            }
            break;
        case 1:
            switch (transform->side) {
                case 0:
                    play("WalkD");
                    break;
                case 1:
                    play("WalkL");
                    spriteFlip = SDL_FLIP_NONE;
                    break;
                case 2:
                    play("WalkU");
                    break;
                case 3:
                    play("WalkL");
                    spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
            }
            break;
        case 2:
            switch (transform->side) {
                case 0:
                    play("AttackD");
                    break;
                case 1:
                    play("AttackL");
                    spriteFlip = SDL_FLIP_NONE;
                    break;
                case 2:
                    play("AttackU");
                    break;
                case 3:
                    play("AttackL");
                    spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
            }
            break;
    }
    
    srcRect.y = animIndex * transform->height;
    
    destRect.x = static_cast<int>(transform->position.x) - entity->scene->camera.x;
    destRect.y = static_cast<int>(transform->position.y) - entity->scene->camera.y;
    
    destRect.w = transform->width * transform->scale;
    destRect.h = transform->height * transform->scale;
}

void SpriteComponent::setTexture(std::string textureID) {
    texture = entity->scene->assets->getTexture(textureID);
}

void SpriteComponent::play(const char* animName) {
    frames = animations[animName].frames;
    animIndex = animations[animName].index;
    speed = animations[animName].speed;
}
