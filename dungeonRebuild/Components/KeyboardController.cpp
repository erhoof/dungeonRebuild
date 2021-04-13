//
//  KeyboardController.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 15/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "KeyboardController.hpp"

void KeyboardController::init() {
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
}

void KeyboardController::update() {
    if (!locked) {
        if (GameEngine::event.type == SDL_KEYDOWN) {
            sprite->actIndex = 1;
            switch (GameEngine::event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    entity->scene->engine->gameScenes["pauseScene"]->currentPlayer = entity->scene->currentPlayer;
                    entity->scene->engine->gameScenes["pauseScene"]->camera = {0,0,0,0};
                    entity->scene->engine->currentScene = entity->scene->engine->gameScenes["pauseScene"];
                    break;
                case SDLK_q:
                    SaveManager::saveFile(entity);
                    GameEngine::runningStatus = false;
                    break;
                case SDLK_w:
                    transform->velocity.y = -1;
                    transform->side = 2;
                    transform->velocity.normalize();
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    transform->side = 0;
                    transform->velocity.normalize();
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    transform->side = 1;
                    transform->velocity.normalize();
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    transform->side = 3;
                    transform->velocity.normalize();
                    break;
                case SDLK_k:
                    sprite->actIndex = 2;
                    if (SDL_GetTicks()/10 - lastAttack > 50) {
                        lastAttack = SDL_GetTicks()/10;
                        
                        switch (transform->side) {
                            case 0:
                                velocityAttack.x = 0;
                                velocityAttack.y = 1;
                                break;
                            case 1:
                                velocityAttack.x = -1;
                                velocityAttack.y = 0;
                                break;
                            case 2:
                                velocityAttack.x = 0;
                                velocityAttack.y = -1;
                                break;
                            case 3:
                                velocityAttack.x = 1;
                                velocityAttack.y = 0;
                                break;
                        }
                        
                        entity->scene->assets->createProjectile(transform->position, velocityAttack, 150, 20, "", "pSlash", transform->side);
                    }
                    break;
                case SDLK_l:
                    if (SDL_GetTicks()/10 - lastAttack > 100 && entity->getComponent<PlayerComponent>().arrows > 0) {
                        lastAttack = SDL_GetTicks()/10;
                        
                        switch (transform->side) {
                            case 0:
                                velocityAttack.x = 0;
                                velocityAttack.y = 1;
                                break;
                            case 1:
                                velocityAttack.x = -1;
                                velocityAttack.y = 0;
                                break;
                            case 2:
                                velocityAttack.x = 0;
                                velocityAttack.y = -1;
                                break;
                            case 3:
                                velocityAttack.x = 1;
                                velocityAttack.y = 0;
                                break;
                        }
                        
                        entity->getComponent<PlayerComponent>().arrows--;
                        entity->scene->assets->createProjectile(transform->position, velocityAttack, 600, 20, "arrow", "pSlash", transform->side);
                    }
                    break;
            }
        } else if (GameEngine::event.type == SDL_KEYUP) {
            sprite->actIndex = 0;
            transform->velocity.x = 0;
            transform->velocity.y = 0;
        }
    }
}
