//
//  MapEditor.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "MapEditorState.hpp"

MapEditorState::MapEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack) : vMapState(renderer,window,timer, stateStack){
    
}
void MapEditorState::handleInput(){
    //check for event
    while ( SDL_PollEvent(&state_event) )
    {
        //quit game when window exit button is pressed
        if (state_event.type == SDL_QUIT)
        {
            endGame();
        }
        //events for left mouse clicks
        if(state_event.type == SDL_MOUSEBUTTONDOWN && state_event.button.button == SDL_BUTTON_LEFT){
            //get current coordinates of mouse
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            
        }
        //events for key presses
        if(state_event.type == SDL_KEYDOWN){
            switch (state_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    //pop self off stack
                    game_stateStack->pop();
                    
                    //TODO:  fix memory leak here: delete this;
                    break;
                case SDLK_UP:
                    shiftMap(ORIENTATION_DOWN);
                    break;
                case SDLK_DOWN:
                    shiftMap(ORIENTATION_UP);
                    break;
                case SDLK_LEFT:
                    shiftMap(ORIENTATION_RIGHT);
                    break;
                case SDLK_RIGHT:
                    shiftMap(ORIENTATION_LEFT);
                    break;
                    
                default:
                    break;
            }
        }
    }
    return;
}
void MapEditorState::render(){
    vMapState::render();
    
    //render the editor buttons
    for(int i = 1; i <= 4;i++){
        SDL_RenderCopy(game_renderer, state_textures[i].texture, &state_textures[i].srcrect, &state_textures[i].dstrect);
    }
    
    SDL_RenderPresent(game_renderer);
    SDL_RenderClear(game_renderer);
}















