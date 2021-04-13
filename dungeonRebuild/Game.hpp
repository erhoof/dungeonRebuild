//
//  Game.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 15/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "ECS.hpp"
#include "GameScene.hpp"
#include "Components/Components.hpp"
#include "LeaderboardManager.hpp"

class Game {
public:    
    static void spawnAlink(int xPos, int yPos, GameScene *gs);
    static void spawnItem(int xPos, int yPos, std::string name, GameScene *gs);
    static void spawnGrass(int xPos, int yPos, GameScene *gs);
    
    static void prepareSplash(GameScene *gs);
    
    static void prepareEnterName(GameScene *gs);
    static void prepareMenuNew(GameScene *gs);
    static void prepareMenuOld(GameScene *gs);
    static void prepareTutorial(GameScene *gs);
    static void prepareLeaderboard(GameScene *gs);
    
    static void preparePause(GameScene *gs);
    static void prepareDeath(GameScene *gs);
    static void prepareEnd(GameScene *gs);
    
    static void addScore(int n, GameScene *gs);
};

#endif /* Game_hpp */
