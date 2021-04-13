//
//  LabelComponent.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "LabelComponent.hpp"

void LabelComponent::render() {
    TextManager::writeText(text.c_str(), entity->getComponent<TransformComponent>().position.x, entity->getComponent<TransformComponent>().position.y, 58, {255, 255, 255});
}
