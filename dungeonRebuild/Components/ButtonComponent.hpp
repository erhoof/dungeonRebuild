//
//  ButtonComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 23/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef ButtonComponent_hpp
#define ButtonComponent_hpp

#include <string>

#include "GameEngine.hpp"
#include "SaveManager.hpp"

class ButtonComponent : public Component {
public:
    std::string tag;
    
    TransformComponent *transform;
    
    ButtonComponent(std::string mTag) : tag(mTag) {}
    
    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }
    
    void update() override;
    
};

#endif /* ButtonComponent_hpp */
