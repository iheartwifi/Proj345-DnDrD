//
//  SetNewMapSizeState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-27.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "SetNewMapSizeState.hpp"
#include <regex>
#include <sstream>
#include "MapEditorState.hpp"

SetNewMapSizeState::SetNewMapSizeState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font) : InputPromptState(renderer,window,timer,stateStack,font, "Please enter the dimensions of the new map in the format #x#. Ex: 10x10"){
}
void SetNewMapSizeState::acceptString(){
    //check if string follows correct format
    bool match = regex_match(workingString, std::regex("^\\d+x\\d+$"));
    if(!match){
        //display error screen
        GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "Input does not follow the correct format.");
        game_stateStack->push(nextState);
        
        return;
    }
    else{
        //get dimensions from string
        std::stringstream *sstream = new std::stringstream(workingString);
        int width;
        *sstream >> width;
        char getRidOfTheX;
        *sstream >> getRidOfTheX;
        int height;
        *sstream >> height;
        
        if(width < 3 || height < 3){
            GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "Map must be a minimum of 3x3.");
            game_stateStack->push(nextState);
            return;
        }
        
        //make map
        GameMap2* newMap = new GameMap2(width, height, Coordinate {0,0}, Coordinate {width-1,height-1}, nullptr, nullptr);
        
        //remove size screen state
        removeSelfFromStateStack();
        
        //push map editor with new map
        GameState* mapEditor = new MapEditorState(game_renderer,game_window,game_timer,game_stateStack,game_font,newMap);
        game_stateStack->push(mapEditor);
    }
   
}
