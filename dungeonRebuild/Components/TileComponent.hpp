//
//  TileComponent.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 16/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef TileComponent_hpp
#define TileComponent_hpp

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "TextureManager.hpp"
#include "GameEngine.hpp"
#include <SDL2/SDL.h>

class SpriteComponent;

class TileComponent : public Component {
public:
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    Vector2D position;
    
    TileComponent(int xSrc, int ySrc, int xPos, int yPos, int tileSize, int mapScale, std::string textureID);
    ~TileComponent() {}
    
    void render() override;
    void update() override;
};

#endif /* TileComponent_hpp */
