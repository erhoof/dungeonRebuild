//
//  SpriteComponent.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 14/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include <map>

#include "SDL2/SDL.h"

#include "GameEngine.hpp"

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "TextureManager.hpp"
#include "Animation.hpp"

class TransformComponent;


class SpriteComponent : public Component {
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    
    bool animated = false;
    int frames, speed;
    
    int animIndex = 0;
    
    std::map<const char*, Animation> animations;
public:
    std::string textureID;
    
    int actIndex = 0;
    double angle = 0;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
    
    SpriteComponent() = default;
    
    SpriteComponent(std::string textureID);
    SpriteComponent(std::string textureID, double angle);
    SpriteComponent(std::string textureID, bool isAnimated);
    ~SpriteComponent() {}
    
    void setTexture(std::string textureID);
    
    void init() override;
    void render() override;
    void update() override;
    
    void play(const char* animName);
};

#endif /* SpriteComponent_hpp */
