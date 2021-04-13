//
//  TextureManager.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 07/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <cstring>

#include "GameEngine.hpp"

extern const char* workingDirectory;

class TextureManager {
    
public:
    static SDL_Texture *loadTexture(const char* filename);
    static void drawTexture(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip);
    static void drawTextureRotated(SDL_Texture * texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip, double angle);
};

#endif /* TextureManager_hpp */
