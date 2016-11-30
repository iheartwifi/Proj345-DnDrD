//
//  PlayGame.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "PlayGameState.hpp"

PlayGameState::PlayGameState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameMap2* map) : vMapState(renderer,window,timer, stateStack, font, map){
    
}
void PlayGameState::handleInput(){
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
                    removeSelfFromStateStack();
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
                case SDLK_w:
                    moveHero(ORIENTATION_UP);
                    break;
                case SDLK_s:
                    moveHero(ORIENTATION_DOWN);
                    break;
                case SDLK_a:
                    moveHero(ORIENTATION_LEFT);
                    break;
                case SDLK_d:
                    moveHero(ORIENTATION_RIGHT);
                    break;

                default:
                    break;
            }
        }
    }
    return;
}
void PlayGameState::render(){
    //render map
    vMapState::render();
    
    SDL_RenderPresent(game_renderer);
    SDL_RenderClear(game_renderer);
}

void PlayGameState::moveHero(Orientation direction){
    state_hero->incrementMoveCounter();
    state_hero->setOrientation(direction);
    
    //determine coordinate of next block
    Coordinate nextBlock = state_hero->getLocationInMap();
    switch (direction) {
        case ORIENTATION_UP:
            nextBlock.y++;
            break;
        case ORIENTATION_DOWN:
            nextBlock.y--;
            break;
        case ORIENTATION_RIGHT:
            nextBlock.x++;
            break;
        case ORIENTATION_LEFT:
            nextBlock.x--;
            break;
        default:
            break;
    }
    
    //exit function if next block does not in map
    if(nextBlock.x < 0 ||
       nextBlock.x >= state_map->getArrayDimensions().x ||
       nextBlock.y < 0 ||
       nextBlock.y >= state_map->getArrayDimensions().y){
        return;
    }
    //exit function if next block can't be moved into
    if(!state_map->getBlock(nextBlock)->canMoveInto()){
        return;
    }
    else{
        if(state_map->getBlock(nextBlock)->getMapType() ==MAP_END)
        {
            //do something
        }
        else{
            //set current block to empty
            state_map->deOccupyBlock(state_hero->getLocationInMap());
            //move character to next block
            state_map->occupyBlock(nextBlock, state_hero); 
        }
    }
    
}
