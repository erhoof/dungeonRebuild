//
//  Projectile.cpp
//  dungeonRebuild
//
//  Created by Pavel Bibichenko on 20/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "ProjectileComponent.hpp"

void ProjectileComponent::init() {
    transform = &entity->getComponent<TransformComponent>();
    transform->velocity = velocity;
    transform->speed = speed;
}

void ProjectileComponent::update() {
    distance += speed;
    if (distance > range)
        entity->destroy();
    else if (transform->position.x > entity->scene->camera.x + entity->scene->camera.w ||
             transform->position.x < entity->scene->camera.x ||
             transform->position.y > entity->scene->camera.y + entity->scene->camera.h ||
             transform->position.y < entity->scene->camera.y)
        entity->destroy();
}
