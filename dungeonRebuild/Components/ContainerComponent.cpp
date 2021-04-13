//
//  ContainerComponent.cpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 15/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "ContainerComponent.hpp"

void ContainerComponent::init() {
    if (!(entity->hasComponent<ItemComponent>())) {
        size_t type = rand() % 6;
        
        switch (type) {
            case 0:
                typeCreate = "heart";
                break;
            case 1:
                typeCreate = "r1";
                break;
            case 2:
                typeCreate = "r5";
                break;
            case 3:
                typeCreate = "r10";
                break;
            case 4:
                typeCreate = "arrow";
                break;
            case 5:
                typeCreate = "heartc";
                break;
        }
        
        entity->addComponent<ItemComponent>(typeCreate);
    }
}

void ContainerComponent::use() {
    Entity *e = &entity->scene->createEntity(GameScene::groupItems);
    e->addComponent<TransformComponent>(entity->getComponent<TransformComponent>().position.x,
                                        entity->getComponent<TransformComponent>().position.y, 16, 16, 4);
    e->addComponent<ColliderComponent>("item", -32, -32, 64, 64);
    e->addComponent<SpriteComponent>(typeCreate, false);
    e->addComponent<ItemComponent>(typeCreate);
}
