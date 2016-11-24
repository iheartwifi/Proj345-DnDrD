//
//  GameState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "GameState.hpp"

GameState::GameState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack){
    this->game_renderer = renderer;
    this->game_window = window;
    this->game_timer = timer;
    this->game_stateStack = stateStack;
}
GameState::~GameState(){
    //delete textures
    for(int i = 0; i < state_textures.size(); i++){
        SDL_DestroyTexture(state_textures[i].texture);
    }
    state_textures.clear();
}

void GameState::run(){
    //limit frame rate to FRAME_RATE
    if ( (SDL_GetTicks() - *game_timer) >= FRAME_RATE )
    {
        this->handleInput();
        this->render();
        
        *game_timer = SDL_GetTicks();
    }
    else{
        //Wait remaining time
        SDL_Delay( FRAME_RATE - (SDL_GetTicks() - *game_timer) + 1 );
    }
}

void GameState::endGame(){
    while(!game_stateStack->empty()){
        game_stateStack->pop();
    }
}

bool GameState::checkIfInside(SDL_Rect dstrect, int x, int y){
    return (x >= dstrect.x &&
            x <= dstrect.x + dstrect.w &&
            y >= dstrect.y &&
            y <= dstrect.y + dstrect.h);
}
