//
//  KeyboardController.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 15/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef KeyboardController_hpp
#define KeyboardController_hpp

#include "GameEngine.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class SpriteComponent;
class TransformComponent;

class KeyboardController : public Component {
    TransformComponent *transform;
    SpriteComponent *sprite;
    
    int lastAttack = 0;
    Vector2D velocityAttack;
    
public:
    bool locked = false;
    
    KeyboardController() {};
    ~KeyboardController() {}
    
    void init() override;
    void update() override;
};

#endif /* KeyboardController_hpp */
