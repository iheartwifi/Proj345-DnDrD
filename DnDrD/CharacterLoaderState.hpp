//
//  CharacterLoaderState.hpp
//  DnDrD
//
//  Created by oscar on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef CharacterLoaderState_hpp
#define CharacterLoaderState_hpp

#include <stdio.h>
#include "InputPromptState.hpp"
#include "DestinationEnum.h"

class CharacterLoaderState: public InputPromptState{
public:
    CharacterLoaderState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, int destination);
private:
    int destination;
    void acceptString();
};

#endif /* CharacterLoaderState_hpp */
