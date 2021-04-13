//
//  InputFieldComponent.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef InputFieldComponent_hpp
#define InputFieldComponent_hpp

#include <string>
#include <cstring>

#include "GameEngine.hpp"
#include "TextManager.hpp"

class InputFieldComponent : public Component {
public:
    char buf[20];
    int curEdit = 0;
    int maxLength = 19;
    bool focused = false;
    
    InputFieldComponent() {
        for (int i=0; i<20; i++)
            buf[i] = 0;
    }
    
    void init() override {
        SDL_StartTextInput();
    }
    
    void update() override;
    void render() override;
};
#endif /* InputFieldComponent_hpp */
