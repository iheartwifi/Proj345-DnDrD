//
//  MainMenuState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include "GameState.hpp"

class MainMenuState : public GameState{
public:
    MainMenuState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameLog* game_log);
    ~MainMenuState();
    void handleInput();
    void render();
};


#endif /* MainMenuState_hpp */
