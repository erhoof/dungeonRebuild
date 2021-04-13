//
//  ContainerComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 15/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef ContainerComponent_hpp
#define ContainerComponent_hpp

#include <ctime>
#include <cstdlib>

#include "ECS.hpp"
#include "ItemComponent.hpp"
#include "TransformComponent.hpp"
#include "ColliderComponent.hpp"
#include "GameScene.hpp"

class ContainerComponent: public Component {
public:
    std::string typeCreate, typeTex;
    
    ContainerComponent() {}
    ~ContainerComponent();
    
    void init();
    
    void use();
};

#endif /* ContainerComponent_hpp */
