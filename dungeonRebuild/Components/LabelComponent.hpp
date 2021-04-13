//
//  LabelComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef LabelComponent_hpp
#define LabelComponent_hpp

#include <string>

#include "TextManager.hpp"

class LabelComponent : public Component {
public:
    std::string text;
    
    LabelComponent(std::string mText) :  text(mText) {}
    
    void render() override;
};

#endif /* LabelComponent_hpp */
