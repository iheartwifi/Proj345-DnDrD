//
//  vMapState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef vMapState_hpp
#define vMapState_hpp

#include <stdio.h>
#include "GameState.hpp"
#include "GameMap2.hpp"
#include "Hero.hpp"

class vMapState : public GameState{
public:
    vMapState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameMap2* map, GameLog* game_log);
    ~vMapState();
    virtual void handleInput() = 0;
    void render();
    
    void shiftMap(Orientation direction);
    
    GameMap2* state_map = NULL;
    Hero* state_hero = NULL;
    
};


#endif /* vMapState_hpp */
