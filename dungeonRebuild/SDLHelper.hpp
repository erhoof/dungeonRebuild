//
//  SDLHelper.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 09/02/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef SDLHelper_hpp
#define SDLHelper_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class SDLHelper {
protected:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    
public:
    SDLHelper(SDL_Window* window, SDL_Renderer* renderer);
    
    void putText(int x, int y, char const* text, int textSize, SDL_Color);
    void putPoint(int x, int y, SDL_Color);
    void putLargePoint(int x, int y, SDL_Color);
    void putLine(int x1, int y1, int x2, int y2, SDL_Color);
    void putRect(int x1, int y1, int width, int height, SDL_Color);
};

#endif /* SDLHelper_hpp */
