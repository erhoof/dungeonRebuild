//
//  TransformComponent.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 14/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "TransformComponent.hpp"

TransformComponent::TransformComponent() {
    position.zero();
}

TransformComponent::TransformComponent(int scale) {
    position.x = 300;
    position.y = 300;
    
    this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y) {
    position.x = x;
    position.y = y;
}

TransformComponent::TransformComponent(float x, float y, int scale) {
    position.x = x;
    position.y = y;
    
    this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y, int scale, int speed) {
    position.x = x;
    position.y = y;
    
    this->scale = scale;
    this->speed = speed;
}


TransformComponent::TransformComponent(float x, float y, int w, int h, int scale) {
    position.x = x;
    position.y = y;
    
    width = w;
    height = h;
    
    this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y, int w, int h, int scale, int speed) {
    position.x = x;
    position.y = y;
    
    width = w;
    height = h;
    
    this->scale = scale;
    this->speed = speed;
}

void TransformComponent::init() {
    velocity.zero();
}

void TransformComponent::update() {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}
