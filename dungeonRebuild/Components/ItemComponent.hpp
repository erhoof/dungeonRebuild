//
//  ItemComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 15/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef ItemComponent_hpp
#define ItemComponent_hpp

#include "ECS.hpp"

class ItemComponent : public Component {
public:
    std::string tag;
    
    ItemComponent(std::string tg) : tag(tg) {}
    ~ItemComponent();
};

#endif /* ItemComponent_hpp */
