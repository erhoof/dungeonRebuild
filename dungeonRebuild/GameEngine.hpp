//
//  GameEngine.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 07/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <cstring>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

#include "TextureManager.hpp"
#include "AssetManager.hpp"
#include "GameObject.hpp"
#include "GameMap.hpp"
#include "GameBackground.hpp"
#include "GameWall.hpp"

#include "ECS.hpp"
#include "Components.hpp"

#include "Vector2D.hpp"

#include "Collision.hpp"
#include "GameScene.hpp"

class ColliderComponent;
class AssetManager;
class GameScene;

class GameEngine {
    SDL_Window *window;
    SDL_DisplayMode displayMode;
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool isRunning() { return runningStatus; }

public:
    const char* name;
    int xSize, ySize;
    bool fullscreen;
    
    static bool runningStatus;
    static bool pause;
    
    static SDL_Renderer *renderer;
    static SDL_Event event;
    
    Uint32 frameStart;
    int frameTime;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    std::map<std::string, GameScene *> gameScenes;
    static GameScene* currentScene;

    GameEngine(const char* name, const char* argv0, int xSize, int ySize, bool fullscreen);

    void run();
};

#endif /* GameEngine_hpp */
