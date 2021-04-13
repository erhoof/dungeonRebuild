//
//  main.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 13/02/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "GameEngine.hpp"

#include "Game.hpp"
#include "GameLauncher.hpp"

int main(int argc, const char * argv[]) {
    GameEngine *gameEngine = new GameEngine("Dungeon Rebuild", argv[0], 1024, 896, false);
    
    // sceneName, mapScale, tileSize, mapSizeX, mapSizeY, tilemap file, tileMapSizeX, tileMapSizeY
    GameScene *mainScene = new GameScene("mainScene",
                                         4, 8, 80, 80,
                                         "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    
    //Add scene to gameEngine
    gameEngine->gameScenes.emplace("mainScene", mainScene);
    
    //Set scene to be current
    gameEngine->currentScene = gameEngine->gameScenes["mainScene"];
    
    //Init scene
    mainScene->init();
    
    // Add assets to scene
    mainScene->addAsset("hud", "/Resources/Assets/Sets/hud.png");
    mainScene->addAsset("player", "/Resources/Assets/Characters/linkSprites.png");
    mainScene->addAsset("enemy", "/Resources/Assets/Characters/alinkSprites.png");
    mainScene->addAsset("collider", "/Resources/Assets/Characters/collider.png");
    mainScene->addAsset("black", "/Resources/Assets/Sets/black.png");
    mainScene->addAsset("arrow", "/Resources/Assets/Sets/arrow.png");
    mainScene->addAsset("r1", "/Resources/Assets/Sets/r1.png");
    mainScene->addAsset("r5", "/Resources/Assets/Sets/r5.png");
    mainScene->addAsset("r10", "/Resources/Assets/Sets/r10.png");
    mainScene->addAsset("heart", "/Resources/Assets/Sets/heart.png");
    mainScene->addAsset("heartc", "/Resources/Assets/Sets/heartc.png");
    mainScene->addAsset("grass", "/Resources/Assets/Sets/grass.png");
    mainScene->addAsset("endgame", "/Resources/Assets/Sets/heartc.png"); // Different textures and sets
    
    //Add background to scene
    mainScene->addBackground("/Resources/Assets/Maps/map1_b.map"); // Background
    mainScene->addBackground("/Resources/Assets/Maps/map1_r.map"); // Roads
    mainScene->addBackground("/Resources/Assets/Maps/map1_c.map"); // Objects
    mainScene->addBackground("/Resources/Assets/Maps/map1_g.map"); // Grass

    //Add walls to scene
    mainScene->addWalls("/Resources/Assets/Maps/map1_w.map"); // To make objects solid
    
    //Add player to scene at xPos, yPos with texture
    mainScene->addPlayer(250, 550, "player");
    
    Game::spawnAlink(1600, 1000, mainScene);
    Game::spawnAlink(1800, 1300, mainScene);
    Game::spawnAlink(1700, 1450, mainScene);
    Game::spawnAlink(200, 1500, mainScene);
    Game::spawnAlink(200, 2000, mainScene);
    Game::spawnAlink(700, 2000, mainScene);
    Game::spawnAlink(550, 1250, mainScene);
    Game::spawnAlink(920, 1600, mainScene);
    Game::spawnItem(200, 1200, "endgame", mainScene);
    
    GameScene *splashScene = new GameScene("splashScene",
                                         4, 8, 80, 80,
                                         "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("splashScene", splashScene);
    gameEngine->currentScene = gameEngine->gameScenes["splashScene"];
    splashScene->init();
    splashScene->addAsset("background", "/Resources/Assets/Sets/Loading.png");
    splashScene->isMenu = true;
    splashScene->addPlayer(0, 0, "");
    Game::prepareSplash(splashScene);
    
    GameScene *enterNameScene = new GameScene("enterNameScene",
                                            4, 8, 80, 80,
                                            "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("enterNameScene", enterNameScene);
    gameEngine->currentScene = gameEngine->gameScenes["enterNameScene"];
    enterNameScene->init();
    enterNameScene->addAsset("background", "/Resources/Assets/Sets/Enter.png");
    enterNameScene->addAsset("black", "/Resources/Assets/Sets/black.png");
    enterNameScene->isMenu = true;
    enterNameScene->addPlayer(0, 0, "");
    Game::prepareEnterName(enterNameScene);
    
    GameScene *menuSceneNew = new GameScene("menuSceneNew",
                                              4, 8, 80, 80,
                                              "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("menuSceneNew", menuSceneNew);
    gameEngine->currentScene = gameEngine->gameScenes["menuSceneNew"];
    menuSceneNew->init();
    menuSceneNew->addAsset("background", "/Resources/Assets/Sets/Menu_New.png");
    menuSceneNew->addAsset("black", "/Resources/Assets/Sets/black.png");
    menuSceneNew->isMenu = true;
    menuSceneNew->addPlayer(0, 0, "");
    Game::prepareMenuNew(menuSceneNew);
    
    GameScene *menuSceneOld = new GameScene("menuSceneOld",
                                            4, 8, 80, 80,
                                            "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("menuSceneOld", menuSceneOld);
    gameEngine->currentScene = gameEngine->gameScenes["menuSceneOld"];
    menuSceneOld->init();
    menuSceneOld->addAsset("background", "/Resources/Assets/Sets/Menu_Old.png");
    menuSceneOld->addAsset("black", "/Resources/Assets/Sets/black.png");
    menuSceneOld->isMenu = true;
    menuSceneOld->addPlayer(0, 0, "");
    Game::prepareMenuOld(menuSceneOld);
    
    GameScene *statsScene = new GameScene("statsScene",
                                            4, 8, 80, 80,
                                            "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("statsScene", statsScene);
    gameEngine->currentScene = gameEngine->gameScenes["statsScene"];
    statsScene->init();
    statsScene->addAsset("background", "/Resources/Assets/Sets/Stats.png");
    statsScene->addAsset("black", "/Resources/Assets/Sets/black.png");
    statsScene->isMenu = true;
    statsScene->addPlayer(0, 0, "");
    Game::prepareLeaderboard(statsScene);
    
    GameScene *tutorialScene = new GameScene("tutorialScene",
                                          4, 8, 80, 80,
                                          "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("tutorialScene", tutorialScene);
    gameEngine->currentScene = gameEngine->gameScenes["tutorialScene"];
    tutorialScene->init();
    tutorialScene->addAsset("background", "/Resources/Assets/Sets/Tutorial.png");
    tutorialScene->addAsset("black", "/Resources/Assets/Sets/black.png");
    tutorialScene->isMenu = true;
    tutorialScene->addPlayer(0, 0, "");
    Game::prepareTutorial(tutorialScene);
    
    GameScene *pauseScene = new GameScene("pauseScene",
                                             4, 8, 80, 80,
                                             "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("pauseScene", pauseScene);
    gameEngine->currentScene = gameEngine->gameScenes["pauseScene"];
    pauseScene->init();
    pauseScene->addAsset("background", "/Resources/Assets/Sets/Pause.png");
    pauseScene->addAsset("black", "/Resources/Assets/Sets/black.png");
    pauseScene->isMenu = true;
    pauseScene->addPlayer(0, 0, "");
    Game::preparePause(pauseScene);
    
    GameScene *deathScene = new GameScene("deathScene",
                                          4, 8, 80, 80,
                                          "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("deathScene", deathScene);
    gameEngine->currentScene = gameEngine->gameScenes["deathScene"];
    deathScene->init();
    deathScene->addAsset("background", "/Resources/Assets/Sets/Death.png");
    deathScene->addAsset("black", "/Resources/Assets/Sets/black.png");
    deathScene->isMenu = true;
    deathScene->addPlayer(0, 0, "");
    Game::prepareDeath(deathScene);
    
    GameScene *endScene = new GameScene("endScene",
                                          4, 8, 80, 80,
                                          "/Resources/Assets/Sets/tilemap.png", 40, 40, gameEngine);
    gameEngine->gameScenes.emplace("endScene", endScene);
    gameEngine->currentScene = gameEngine->gameScenes["endScene"];
    endScene->init();
    endScene->addAsset("background", "/Resources/Assets/Sets/End.png");
    endScene->addAsset("black", "/Resources/Assets/Sets/black.png");
    endScene->isMenu = true;
    endScene->addPlayer(0, 0, "");
    Game::prepareEnd(endScene);
    
    //Run engine with scene
    gameEngine->currentScene = gameEngine->gameScenes["splashScene"];
    gameEngine->run();
    
    return 0;
}

