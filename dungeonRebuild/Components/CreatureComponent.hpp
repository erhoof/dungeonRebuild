//
//  CreatureComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 26/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef CreatureComponent_hpp
#define CreatureComponent_hpp

#include <fstream>
#include <ctime>

#include "ECS.hpp"
#include "GameEngine.hpp"

class PlayerComponent;

class CreatureComponent : public Component {
public:
    int health,
        maxHealth;
    
    SDL_Rect srcRect, destRect;
    
    CreatureComponent() : health(6), maxHealth(6) {}
    CreatureComponent(int max) : health(max), maxHealth(max) {}
    
    ~CreatureComponent() {}
    
    void update() override;
    void render() override;
};

#endif /* CreatureComponent_hpp */
