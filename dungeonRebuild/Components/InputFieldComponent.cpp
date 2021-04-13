//
//  InputFieldComponent.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "InputFieldComponent.hpp"

void InputFieldComponent::update() {
    switch (GameEngine::event.type) {
        case SDL_KEYDOWN:
            switch (GameEngine::event.key.keysym.sym) {
                case SDLK_BACKSPACE:
                    for (int i=0; i<maxLength; i++)
                        buf[i]=0;
                    curEdit = 0;
                    break;
            }
            if (GameEngine::event.key.keysym.sym > SDLK_0 && GameEngine::event.key.keysym.sym < SDLK_z)
                if (curEdit < maxLength) {
                    buf[curEdit] = GameEngine::event.key.keysym.sym;
                    curEdit++;
                }
            break;
    }
}

void InputFieldComponent::render() {
    //TextManager::writeText(buf, 200, 200, 50, {255, 255, 255});
    TextManager::writeText(buf, entity->getComponent<TransformComponent>().position.x, entity->getComponent<TransformComponent>().position.y, 58, {0, 0, 0});
}
