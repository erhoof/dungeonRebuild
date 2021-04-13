//
//  AssetManager.cpp
//  dungeonRebuild
//
//  Created by Pavel Bibichenko on 20/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "AssetManager.hpp"

AssetManager::AssetManager(Manager* mgr, GameScene *sc) : manager(mgr), scene(sc) {}

void AssetManager::addTexture(std::string id, const char* filepath) {
    textures.emplace(id, TextureManager::loadTexture(filepath));
}

SDL_Texture *AssetManager::getTexture(std::string id) {
    return textures[id];
}

void AssetManager::createProjectile(Vector2D position, Vector2D velocity, int range, int speed, std::string textureID, std::string tag, int side) {
    double angle = 90;
    switch (side) {
        case 0:
            angle = 180;
            break;
        case 1:
            angle = 270;
            break;
        case 2:
            angle = 360;
            break;
        case 3:
            angle = 90;
            break;
    }
    
    auto& projecttile(manager->addEntity(scene));
    
    projecttile.addComponent<TransformComponent>(position.x, position.y, 20, 20, 4);
    projecttile.addComponent<SpriteComponent>(textureID, angle);
    projecttile.addComponent<ProjectileComponent>(range, speed, velocity, tag);
    projecttile.addComponent<ColliderComponent>("projectile", 20, 30, 20, 30);
    
    projecttile.addGroup(GameScene::groupProjectiles);
}
