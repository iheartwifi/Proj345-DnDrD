//
//  SaveMapState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-27.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef SaveMapState_hpp
#define SaveMapState_hpp

#include <stdio.h>
#include "InputPromptState.hpp"
#include "GameMap2.hpp"

class SaveMapState : public InputPromptState{
    GameMap2* map;
    void acceptString();
public:
    SaveMapState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameMap2* map);
};


#endif /* SaveMapState_hpp */
