//
//  Collision.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 16/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "Collision.hpp"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) {
    return (rectA.x + rectA.w >= rectB.x &&
            rectB.x + rectB.w >= rectA.x &&
            rectA.y + rectA.h >= rectB.y &&
            rectB.y + rectB.h >= rectA.y);
}

bool Collision::AABB(const ColliderComponent& colliderA, const ColliderComponent& colliderB) {
    return AABB(colliderA.collider, colliderB.collider) ? true : false;
}
