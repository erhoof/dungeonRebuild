//
//  GameLauncher.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 16/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef GameLauncher_hpp
#define GameLauncher_hpp

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class GameLauncher {
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    SDL_Event event;
    
    Uint32 frameStart;
    int frameTime;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    bool runningStatus = true;
    bool saveExists = false;
    int exitStatus = 1;
    
    int *hp, *maxHp,
        *rupies, *arrows,
        *bombs, *xPos, *yPos;
    
    std::string p1, p2, p3;
    
    const char *wd;
    
    GameLauncher(int *mHp, int *mMaxHp, int *mRupies, int *mArrows, int *mBombs, int *mXPos, int *mYPos, const char *argv0) :
                hp(mHp), maxHp(mMaxHp), rupies(mRupies), arrows(mArrows), bombs(mBombs), xPos(mXPos), yPos(mYPos) {
                    size_t i;
                    wd = argv0;
                    for (i=strlen(wd)-1; wd[i]!='/'; i--);
                    for (i--; wd[i]!='/'; i--);
                    ((char*)wd)[i]=0;
                    
                    p1 = "None.";
                    p2 = "None.";
                    p3 = "None.";
                    
                    char *leaderPath = new char[255];
                    strcpy(leaderPath, wd);
                    strcat(leaderPath, "/Resources/Assets/Settings/leaderboard.ini");
                    char *savePath = new char[255];
                    strcpy(savePath, wd);
                    strcat(savePath, "/Resources/Assets/Settings/mainSave.sav");
                    
                    std::ifstream leaderboardFile,
                            saveFile;
                    leaderboardFile.open(leaderPath);
                    saveFile.open(savePath);
                    
                    if (saveFile.is_open()) {
                        saveExists = true;
                        
                        saveFile >> *xPos;
                        saveFile >> *yPos;
                        saveFile >> *hp;
                        saveFile >> *maxHp;
                        saveFile >> *arrows;
                        saveFile >> *rupies;
                        saveFile >> *bombs;
                    }
                    
                    getline(leaderboardFile, p1);
                    getline(leaderboardFile, p2);
                    getline(leaderboardFile, p3);
                    
                    if (p1 == "")
                        p1 = "None.";
                    
                    if (p2 == "")
                        p2 = "None.";
                    
                    if (p3 == "")
                        p3 = "None.";
                    
                    leaderboardFile.close();
                    saveFile.close();
                };
    
    ~GameLauncher();
    
    void run() {
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("Launcher", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 480, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        TTF_Init();
        
        render();
        
        while (runningStatus) {
            frameStart = SDL_GetTicks();
            
            handleEvents();
            
            frameTime = SDL_GetTicks() - frameStart;
            
            if (frameDelay > frameTime) {
                SDL_Delay(frameDelay - frameTime);
            }
        }
        
        TTF_Quit();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
    
    void render() {
        SDL_RenderClear(renderer);
        
        writeText("6N6N4EHKO 7.P N582 2019", 18, 20, 21, {255, 255, 255});
        writeText("Dungeon Rebuild", 60, 50, 24, {255, 255, 255});
        createButton("New Game", 20, 110, 130, 40);
        if (saveExists)
            createButton("Continue", 170, 110, 130, 40);
        
        writeText("Leaderboard: ", 85, 180, 24, {255, 255, 255});
        
        writeText(p1, 60, 220, 20, {255, 255, 255});
        writeText(p2, 60, 250, 20, {255, 255, 255});
        writeText(p3, 60, 280, 20, {255, 255, 255});
        
        createButton("Quit", 90, 380, 130, 40);
        
        writeText("v0.12", 257, 440, 18, {255, 255, 255});
        
        SDL_RenderPresent(renderer);
    }
    
    void handleEvents() {
        SDL_PollEvent(&event);
        
        switch(event.type) {
            case SDL_QUIT:
                runningStatus = false;
                exitStatus = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "Click: " << event.motion.x << "/" << event.motion.y << "\n";
                
                if (event.motion.x >= 75 && event.motion.x <= 150
                    && event.motion.y >=125 && event.motion.y <= 148) {
                    exitStatus = 1;
                    runningStatus = 0;
                    nullSave();
                }
                
                if (event.motion.x >= 170 && event.motion.x <= 300
                    && event.motion.y >= 110 && event.motion.y <= 150
                    && saveExists) {
                    exitStatus = 2;
                    runningStatus = 0;
                }
                
                if (event.motion.x >= 90 && event.motion.x <= 220
                    && event.motion.y >= 380 && event.motion.y <= 420) {
                    exitStatus = 0;
                    runningStatus = 0;
                }
                
                break;
        }
    }
    
    void nullSave() {
        char *path = new char[255];
        strcpy(path, wd);
        strcat(path, "/Resources/Assets/Settings/mainSave.sav");
        
        remove(path);
    }
    
    void writeText(std::string text, int xPos, int yPos, int size, SDL_Color color) {
        TTF_Font *font = TTF_OpenFont("/System/Library/Fonts/SFNSText.ttf", size);
        
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
        
        SDL_Rect fontRect;
        fontRect.x = xPos;
        fontRect.y = yPos;
        fontRect.w = textSurface->w;
        fontRect.h = textSurface->h;
        
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        
        SDL_RenderCopy(renderer, textTexture, NULL, &fontRect);
        
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
        TTF_CloseFont(font);
    }

    void createButton(const char* text, int x, int y, int w, int h) {
        drawRect(x, y, w, h, {30, 180, 220, 250});
        drawRect(x+5, y+5, w-10, h-10, {30, 220, 220, 250});
        writeText(text, x+10, y+10, 20, {255, 255, 255});
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    
    void drawRect(int x, int y, int w, int h, SDL_Color color) {
        SDL_Rect rect;
        
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
};

#endif /* GameLauncher_hpp */
