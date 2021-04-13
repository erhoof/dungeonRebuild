//
//  TransformComponent.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 14/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "ECS.hpp"
#include "Vector2D.hpp"

#include "SpriteComponent.hpp"

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;
    
    int height = 32;
    int width = 32;
    int scale = 1;
    int side = 0;
    
    int speed = 5;
    
    TransformComponent();
    TransformComponent(int scale);
    TransformComponent(float x, float y);
    TransformComponent(float x, float y, int scale);
    TransformComponent(float x, float y, int scale, int speed);
    TransformComponent(float x, float y, int w, int h, int scale);
    TransformComponent(float x, float y, int w, int h, int scale, int speed);
    ~TransformComponent() {}
    
    void init() override;
    void update() override;
    
    void moveTo(Vector2D pos) {
        velocity = pos;
        velocity -= position;
        velocity.normalize();
        
        if ((abs(velocity.x) - abs(velocity.y)) < 0)
            if (position.y > pos.y)
                side = 2;
            else
                side = 0;
        else
            if (position.x > pos.x)
                side = 1;
            else
                side = 3;
    }
};

#endif /* TransformComponent_hpp */
