//
//  SetNewMapSizeState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-27.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef SetNextMapSizeState_hpp
#define SetNextMapSizeState_hpp

#include <stdio.h>
#include "InputPromptState.hpp"
#include "GameMap2.hpp"

class SetNextMapSizeState : public InputPromptState{
    void acceptString();
    GameMap2* map;
public:
    SetNextMapSizeState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameMap2* map);
};


#endif /* SetNextMapSizeState_hpp */
