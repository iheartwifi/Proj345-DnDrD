//
//  TextInputState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef TextInputState_hpp
#define TextInputState_hpp

#include <stdio.h>
#include "GameState.hpp"
#include "SDL2_ttf/SDL_ttf.h"

class MessageDisplayerState : public GameState{
    
    std::string messageToDisplay = "";
public:
    TTF_Font* game_font;
    MessageDisplayerState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message);
    void handleInput();
    void render();
    
};



#endif /* TextInputState_hpp */
