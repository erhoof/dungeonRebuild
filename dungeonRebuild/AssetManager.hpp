//
//  AssetManager.hpp
//  dungeonRebuild
//
//  Created by Pavel Bibichenko on 20/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <map>
#include <string>
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include "GameScene.hpp"

class AssetManager {
    std::map<std::string, SDL_Texture *> textures;
    Manager *manager;
    GameScene *scene;
    
public:
    AssetManager(Manager *mgr, GameScene *sc);
    ~AssetManager() {
        delete manager;
    };
    
    void addTexture(std::string id, const char* filepath);
    SDL_Texture *getTexture(std::string id);
    
    void createProjectile(Vector2D position, Vector2D velocity, int range, int speed, std::string textureID, std::string tag, int side);
};

#endif /* AssetManager_hpp */
