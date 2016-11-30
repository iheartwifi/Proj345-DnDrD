//
//  SaveMapState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-27.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "SaveMapState.hpp"
#include <fstream>
SaveMapState::SaveMapState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameMap2* map) : InputPromptState(renderer,window,timer,stateStack,font, "Please enter the name of the map to save.", game_log){
    this->map = map;
}

void SaveMapState::acceptString(){
    
    //go to the first map in campaign
    while(map->getPreviousMap() != nullptr){
        map = map->getPreviousMap();
    }
    if(workingString.length() > 0){
        std::ofstream out;
        out.open("maps/" + workingString + ".txt");
        out << *map;
        out.close();
        
        //exit map editor
        removeSelfFromStateStack();
        game_stateStack->top()->removeSelfFromStateStack();
    }
    else{
        //display error screen
        GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "You must enter a name to save.", game_log);
        game_stateStack->push(nextState);
    }
   
}
