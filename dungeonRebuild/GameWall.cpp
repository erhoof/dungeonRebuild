//
//  GameWall.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 03/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "GameWall.hpp"

bool GameWall::checkDestination (SDL_Rect collider) {
    int x = collider.x/tileSize/mapScale;
    int y = collider.y/tileSize/mapScale;
    int w = collider.w/mapScale - 2;
    int h = collider.h/mapScale - 2;
    
    if (map[y][x] ||
        map[y+h][x] ||
        map[y][x+w] ||
        map[y+h][x+w])
        return true;
    
    return false;
}
