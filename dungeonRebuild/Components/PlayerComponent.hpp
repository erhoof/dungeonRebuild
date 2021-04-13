//
//  PlayerComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 10/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef PlayerComponent_hpp
#define PlayerComponent_hpp

#include "ECS.hpp"

class PlayerComponent : public Component {
public:
    int rupies,
        bombs,
        arrows;
    
    char name[20];
    
    PlayerComponent() : rupies(0), bombs(0), arrows(10) {};
    ~PlayerComponent();
    
};
#endif /* PlayerComponent_hpp */
