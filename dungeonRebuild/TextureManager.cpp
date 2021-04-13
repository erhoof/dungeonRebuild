//
//  TextureManager.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 07/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture *TextureManager::loadTexture(const char* filename) {
    char *fullPath = new char[255];
    strcpy(fullPath, workingDirectory);
    strcat(fullPath, filename);
    
    std::cout << "[TextureManager - Load] " << filename;
    
    SDL_Surface *tmpSurface = IMG_Load(fullPath);
    
    if (tmpSurface == NULL)
        std::cout << " - [Error]\n";
    else
        std::cout << " - [Done]\n";
    
    SDL_Texture *newTexture = SDL_CreateTextureFromSurface(GameEngine::renderer, tmpSurface);
    
    SDL_free(tmpSurface);
    
    delete[] fullPath;
    return newTexture;
}

void TextureManager::drawTexture(SDL_Texture * texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(GameEngine::renderer, texture, &srcRect, &destRect, NULL, NULL, flip);
}

void TextureManager::drawTextureRotated(SDL_Texture * texture, SDL_Rect srcRect, SDL_Rect destRect, SDL_RendererFlip flip, double angle) {
    SDL_RenderCopyEx(GameEngine::renderer, texture, &srcRect, &destRect, angle, NULL, flip);
}
