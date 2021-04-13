//
//  ColliderComponent.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 15/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef ColliderComponent_hpp
#define ColliderComponent_hpp

#include <string>
#include <SDL2/SDL.h>
#include "Components.hpp"
#include "GameEngine.hpp"

class ColliderComponent : public Component {
public:
    SDL_Rect collider;
    TransformComponent* transform;
    std::string tag;
    bool initWithSizes = false;
    int offsetX=0, offsetY=0;

    ColliderComponent() = default;
    ColliderComponent(std::string t);
    ColliderComponent(std::string t, int x, int y, int w, int h);
    ColliderComponent(std::string t, int w, int h);
    ~ColliderComponent() {}
    
    void init() override;
    void update() override;
    void render() override;
};

#endif /* ColliderComponent_hpp */

