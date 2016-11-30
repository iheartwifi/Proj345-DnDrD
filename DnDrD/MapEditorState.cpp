//
//  MapEditor.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "MapEditorState.hpp"
#include "MessageDisplayerState.hpp"
#include "SaveMapState.hpp"
#include "SetNextMapSizeState.hpp"

MapEditorState::MapEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameMap2* map, GameLog* game_log) : vMapState(renderer,window,timer, stateStack, font, map, game_log){
    
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
            
            
            
            //Determine if a toolbar button was pressed
            for(int i = 1; i < state_textures.size()-1; i++){
                if(checkIfInside(state_textures[i].dstrect, mouseX, mouseY)){
                    if(i >= 9){
                        switch(i){
                            case 9:
                                if(state_map->validateMap()){
                                    if(state_map->getNextMap() == nullptr){
                                        GameState *nextState = new SetNextMapSizeState(game_renderer, game_window, game_timer, game_stateStack, game_font, state_map);
                                        game_stateStack->push(nextState);
                                    }
                                    else{
                                        state_map = state_map->getNextMap();
                                    }
                                }
                                else{
                                    GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "Cannot go to next map because current map is not valid.", game_log);
                                    game_stateStack->push(nextState);
                                }
                                break;
                            case 10:
                                if(state_map->validateMap()){
                                    //save map
                                    GameState *nextState = new SaveMapState(game_renderer, game_window, game_timer, game_stateStack, game_font, state_map);
                                    game_stateStack->push(nextState);
                                }
                                else{
                                    GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "Cannot save map because it is not valid.", game_log);
                                    game_stateStack->push(nextState);
                                }
                                break;
                            default: break;
                        }
                    }
                    else{
                        //if selection is already made then deselect
                        if(AddSelection == i){
                            AddSelection = 0;
                        }
                        //otherwise select
                        else{
                            AddSelection = i;
                        }
                    }
                }
            }
            
            //if a selection is made, determine if a map was pressed
            if(AddSelection != 0){
                for(int r = 0; r < state_map->getArrayDimensions().y; r++){
                    for(int c = 0; c < state_map->getArrayDimensions().x; c++){
                        if(checkIfInside(state_map->getBlock(c, r)->dstrect, mouseX, mouseY)){
                            switch (AddSelection) {
                                case 1:
                                    state_map->fillcell(Coordinate{c,r}, STONE);
                                    break;
                                case 2:
                                    state_map->fillcell(Coordinate{c,r}, GRASS);
                                    break;
                                case 3:
                                    state_map->fillcell(Coordinate{c,r}, WALL);
                                    break;
                                case 4:
                                    state_map->fillcell(Coordinate{c,r}, WATER);
                                    break;
                                case 5:
                                    //set startblock
                                    if(state_map->getBlock(c, r)->canMoveInto()){
                                        state_map->setStartingBlock(Coordinate{c,r});
                                    }
                                    break;
                                case 6:
                                    //set endblock
                                    state_map->setEndingBlock(Coordinate{c,r});
                                    break;
                                case 7:
                                    //TODO: allow item to load
                                case 8:
                                    //TODO: allow character to load
                                default:
                                    break;
                            }
                        }
                    }
                }
            }
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
    for(int i = 1; i <= 10;i++){
        SDL_RenderCopy(game_renderer, state_textures[i].texture, &state_textures[i].srcrect, &state_textures[i].dstrect);
    }
    
    //render hero at starting block
    if(checkIfInside(SDL_Rect{0,0,WINDOW_WIDTH,WINDOW_HEIGHT-TOOLBAR_PANE_HEIGHT}, state_map->getBlock(state_map->getStartingBlock())->dstrect.x, state_map->getBlock(state_map->getStartingBlock())->dstrect.y+1)){
        
        SDL_RenderCopy(game_renderer, state_textures[0].texture, &state_textures[0].srcrect, &state_map->getBlock(state_map->getStartingBlock())->dstrect );
    }
    
    
    SDL_RenderPresent(game_renderer);
    SDL_RenderClear(game_renderer);
}













