//
//  PlayGame.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef PlayGame_hpp
#define PlayGame_hpp

#include <stdio.h>
#include "GameState.hpp"
#include "vMapState.hpp"

class PlayGameState : public vMapState{
public:
    PlayGameState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack);
    void handleInput();
    void render();
    
    void moveHero(Orientation direction);
};

#endif /* PlayGame_hpp */
