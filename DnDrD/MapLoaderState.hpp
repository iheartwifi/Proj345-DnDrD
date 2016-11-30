//
//  MapLoaderState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-27.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef MapLoaderState_hpp
#define MapLoaderState_hpp

#include <stdio.h>
#include "InputPromptState.hpp"
#include "DestinationEnum.h"

class MapLoaderState : public InputPromptState{
public:
    MapLoaderState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, int destination);
private:
    int destination;
    void acceptString();
};


#endif /* MapLoaderState_hpp */
