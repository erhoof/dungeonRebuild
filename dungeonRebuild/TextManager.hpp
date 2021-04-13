//
//  TextManager.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 10/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef TextManager_hpp
#define TextManager_hpp

#include <SDL2_ttf/SDL_ttf.h>

#include "GameEngine.hpp"

//extern const char* workingDirectory;

class TextManager {
    static void write(const char* text, int xPos, int yPos, int size, SDL_Color color);
    
public:
    static void writeText(const char* text, int xPos, int yPos, int size, SDL_Color color) {
        write(text, xPos, yPos, size, color);
    }
    
    static void writeText(int number, int xPos, int yPos, int size, SDL_Color color) {
        char buf[16];
        sprintf(buf, "%d", number);
        
        write(buf, xPos, yPos, size, color);
    }
    
};

#endif /* TextManager_hpp */
