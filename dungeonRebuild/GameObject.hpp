//
//  GameObject.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 09/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "GameEngine.hpp"

class GameScene;

class GameObject {
    GameScene *scene;
    
    int xPos, yPos;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    
public:
    GameObject(const char *textureFile, int xPos, int yPos);
    
    void update();
    void render();
};

#endif /* GameObject_hpp */
