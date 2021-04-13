//
//  EnemyAIComponent.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 26/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "EnemyAIComponent.hpp"

void EnemyAIComponent::init() {
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
}

void EnemyAIComponent::update() {
    for (auto& it : entity->scene->manager->getGroup(GameScene::groupPlayers)) {
        int xp = it->getComponent<TransformComponent>().position.x,
            yp = it->getComponent<TransformComponent>().position.y,
            xe = transform->position.x,
            ye = transform->position.y;
    
        Vector2D pos;
        Vector2D velocity;
        pos.x = xp;
        pos.y = yp;
        
        if (abs(xp - xe) <= attackRadius &&
            abs(yp - ye) <= attackRadius) {
            transform->moveTo(pos);
            sprite->actIndex = 1;
        } else {
            sprite->actIndex = 0;
            transform->velocity.zero();
        }
        
        //if (animated)
        //srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        
        if (abs(xp - xe) <= weaponRadius &&
            abs(yp - ye) <= weaponRadius) {
            if (SDL_GetTicks()/10 - lastAttack > 100) {
                lastAttack = SDL_GetTicks()/10;
                sprite->actIndex = 2;
                
                velocity = pos;
                velocity -= transform->position;
                velocity.normalize();
                entity->scene->assets->createProjectile(transform->position, velocity, 300, 10, "", "slash", transform->side);
                
            } else if (SDL_GetTicks()/10 - lastAttack > 35)
                sprite->actIndex = 0;
            else
                sprite->actIndex = 2;
            transform->velocity.zero();
        }
    }
}
