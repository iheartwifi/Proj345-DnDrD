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

class TextInputState : public GameState{
    TTF_Font* game_font;
public:
    TextInputState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font);
    void handleInput();
    void render();
    
};



#endif /* TextInputState_hpp */
