//
//  SetNewMapSizeState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-27.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef SetNewMapSizeState_hpp
#define SetNewMapSizeState_hpp

#include <stdio.h>
#include "InputPromptState.hpp"
#include "GameMap2.hpp"

class SetNewMapSizeState : public InputPromptState{
    void acceptString();
public:
    SetNewMapSizeState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font);
};


#endif /* SetNewMapSizeState_hpp */
