//
//  GameEngine.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 07/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "GameEngine.hpp"

const char *workingDirectory;

SDL_Renderer *GameEngine::renderer = nullptr;
SDL_Event GameEngine::event;

bool GameEngine::runningStatus;
bool GameEngine::pause;

GameScene *GameEngine::currentScene;

GameEngine::GameEngine(const char* name, const char* argv0, int xSize, int ySize, bool fullscreen) {
    pause = false;
    
    size_t i;
    workingDirectory = argv0;
    for (i=strlen(workingDirectory)-1; workingDirectory[i]!='/'; i--);
    for (i--; workingDirectory[i]!='/'; i--);
    ((char*)workingDirectory)[i]=0;
    
    srand(time(0));
    
    this->name = name;
    this->xSize = xSize;
    this->ySize = ySize;
    this->fullscreen = fullscreen;
    
    Uint32 sdlFlags = 0;
    
    displayMode.w = xSize;
    displayMode.h = ySize;
    
    if (fullscreen)
        sdlFlags = SDL_WINDOW_FULLSCREEN;
    
    std::cout << "[GameEngine - Main] " << name << std::endl;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "[GameEngine - Init] SDL initialization - [Done]\n";
        
        std::cout << "[GameEngine - Window] Window initialization";
        window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w, displayMode.h, sdlFlags);
        if (window)
            std::cout << " - [Done]\n";
        else
            std::cout << " - [Error]\n";
        
        std::cout << "[GameEngine - Renderer] Renderer initialization";
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer)
            std::cout << " - [Done]\n";
        else
            std::cout << " - [Error]\n";
        
        runningStatus = true;
        
        TTF_Init();
    } else {
        std::cout << "[GameEngine] Initialization error. Closing...\n";
        runningStatus = false;
        
        return;
    }
}

void GameEngine::run() {
    while (runningStatus) {
        frameStart = SDL_GetTicks();
        
        handleEvents();
        update();
        render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    clean();
}

void GameEngine::handleEvents() {
    SDL_PollEvent(&event);
    
    switch(event.type) {
        case SDL_QUIT:
            runningStatus = false;
            break;
    }
}

void GameEngine::update() {
    if (!pause)
        currentScene->update();
}

void GameEngine::render() {
    if (!pause) {
        SDL_RenderClear(renderer);
    
        currentScene->render();
    
        SDL_RenderPresent(renderer);
    }
}

void GameEngine::clean() {
    std::cout << "[GameEngine] Session closed.\n";
    
    /* if (currentScene->currentPlayer->getComponent<CreatureComponent>().health != 0) {
        std::ofstream saveFile;
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/mainSave.sav");
        
        remove(fullPath);
        saveFile.open(fullPath);
        saveFile << currentScene->currentPlayer->getComponent<TransformComponent>().position.x;
        saveFile << " ";
        
        saveFile << currentScene->currentPlayer->getComponent<TransformComponent>().position.y;
        saveFile << " ";
        
        saveFile << currentScene->currentPlayer->getComponent<CreatureComponent>().health;
        saveFile << " ";
        
        saveFile << currentScene->currentPlayer->getComponent<CreatureComponent>().maxHealth;
        saveFile << " ";
        
        saveFile << currentScene->currentPlayer->getComponent<PlayerComponent>().arrows;
        saveFile << " ";
        
        saveFile << currentScene->currentPlayer->getComponent<PlayerComponent>().rupies;
        saveFile << " ";
        
        saveFile << currentScene->currentPlayer->getComponent<PlayerComponent>().bombs;
        saveFile << " ";
        saveFile.close();
    } */
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
