//
//  EnemyAIComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 26/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef EnemyAIComponent_hpp
#define EnemyAIComponent_hpp

#include <random>

#include "ECS.hpp"
#include "GameEngine.hpp"

extern Manager manager;

class EnemyAIComponent : public Component {
    TransformComponent *transform;
    SpriteComponent *sprite;
    int attackRadius;
    int weaponRadius = 80;
    int lastAttack = 0;
    
public:
    EnemyAIComponent() : attackRadius(200) {}
    EnemyAIComponent(int radius) : attackRadius(radius) {}
    EnemyAIComponent(int radius, int speed) : attackRadius(radius) {}

    ~EnemyAIComponent() {}
    
    void init() override;
    void update() override;
};

#endif /* EnemyAIComponent_hpp */
