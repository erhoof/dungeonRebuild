//
//  TextManager.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 10/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "TextManager.hpp"

void TextManager::write(const char* text, int xPos, int yPos, int size, SDL_Color color) {
    if (text[0] == 0)
        return;
    
    char *fullPath = new char[255];
    strcpy(fullPath, workingDirectory);
    strcat(fullPath, "/Resources/Assets/Sets/return_of_ganon.ttf");
    
    TTF_Font *font = TTF_OpenFont(fullPath, size);
    if (!font)
        return;
    
    delete[] fullPath;
    
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, color);
    
    SDL_Rect fontRect;
    fontRect.x = xPos;
    fontRect.y = yPos;
    fontRect.w = textSurface->w;
    fontRect.h = textSurface->h;
    
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(GameEngine::renderer, textSurface);
    
    SDL_RenderCopy(GameEngine::renderer, textTexture, NULL, &fontRect);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
}
