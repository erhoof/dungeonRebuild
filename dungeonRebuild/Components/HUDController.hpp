//
//  HUDController.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/04/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef HUDController_hpp
#define HUDController_hpp

#include "ECS.hpp"
#include "GameEngine.hpp"
#include "TextManager.hpp"

class HUDController : public Component {
    SDL_Texture *texture;
    
    SDL_Rect srcRect, destRect;
    TransformComponent *transform;
    
public:
    std::string textureID;
    
    HUDController(std::string textureID);
    ~HUDController() {}
    
    void init() override;
    void render() override;
};

#endif /* HUDController_hpp */
