//
//  ItemLoaderState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-29.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef ItemLoaderState_hpp
#define ItemLoaderState_hpp

#include <stdio.h>
#include "InputPromptState.hpp"
#include "DestinationEnum.h"


class ItemLoaderState : public InputPromptState{
public:
    ItemLoaderState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, int destination);
private:
    int destination;
    void acceptString();
};

#endif /* ItemLoaderState_hpp */
