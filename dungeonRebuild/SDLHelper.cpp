//
//  SDLHelper.cpp
//  graphBuilder
//
//  Created by Pavel Bibichenko on 09/02/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "SDLHelper.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

SDLHelper::SDLHelper(SDL_Window *newWindow, SDL_Renderer *newRenderer) {
    window = newWindow;
    renderer = newRenderer;
}

void SDLHelper::putText(int x, int y, char const* text, int fontSize, SDL_Color textColor) {
    TTF_Font* font = TTF_OpenFont("/Library/Fonts/Trebuchet MS.ttf", fontSize);
    
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text, textColor);
    if (textSurface == NULL)
        std::cout << "ERR.";
    SDL_Rect fontRect;
    fontRect.x = x;
    fontRect.y = y;
    fontRect.w = textSurface->w;
    fontRect.h = textSurface->h;
    
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    
    SDL_RenderCopy(renderer, textTexture, NULL, &fontRect);
    
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
}

void SDLHelper::putPoint(int x, int y, SDL_Color pointColor) {
    SDL_Color oldColor;
    SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
    
    SDL_SetRenderDrawColor(renderer, pointColor.r, pointColor.g, pointColor.b, pointColor.a);
    
    SDL_RenderDrawPoint(renderer, x, y);
    
    SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

void SDLHelper::putLargePoint(int x, int y, SDL_Color pointColor) {
    SDL_Color oldColor;
    SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = 5;
    rect.h = 5;
    
    SDL_SetRenderDrawColor(renderer, pointColor.r, pointColor.g, pointColor.b, pointColor.a);
    
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

void SDLHelper::putLine(int x1, int y1, int x2, int y2, SDL_Color lineColor) {
    SDL_Color oldColor;
    SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
    
    SDL_SetRenderDrawColor(renderer, lineColor.r, lineColor.g, lineColor.b, lineColor.a);
    
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    
    SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

void SDLHelper::putRect(int x, int y, int width, int height, SDL_Color rectColor) {
    SDL_Color oldColor;
    SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.b, &oldColor.a);
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    
    SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, rectColor.a);
    
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}
