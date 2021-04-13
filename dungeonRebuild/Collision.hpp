//
//  Collision.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 16/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <SDL2/SDL.h>
#include "ColliderComponent.hpp"

class ColliderComponent;

class Collision {
public:
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
    static bool AABB(const ColliderComponent& colliderA, const ColliderComponent& colliderB);
};

#endif /* Collision_hpp */
