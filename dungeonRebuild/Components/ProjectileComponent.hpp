//
//  Projectile.hpp
//  dungeonRebuild
//
//  Created by Pavel Bibichenko on 20/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include "GameEngine.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include "Vector2D.hpp"

enum ProjectileType: size_t {
    slash,
    playerSlash,
    arrow,
    playerAllow
};

class ProjectileComponent : public Component {
    TransformComponent *transform;
    int range = 0;
    int speed = 0;
    int distance = 0;
    Vector2D velocity;
    
public:
    std::string tag;
    
    ProjectileComponent (int rg, int sp, Vector2D vel, std::string tp) : range(rg), speed(sp), velocity(vel), tag(tp) {};
    
    void init() override;
    void update() override;
};

#endif /* Projectile_hpp */
