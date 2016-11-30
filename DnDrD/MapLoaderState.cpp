//
//  MapLoaderState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-27.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "MapLoaderState.hpp"
#include <fstream>
#include "GameMap2.hpp"
#include "PlayGameState.hpp"
#include "MapEditorState.hpp"
#include "SetNewMapSizeState.hpp"


MapLoaderState::MapLoaderState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, int destination) : InputPromptState(renderer,window,timer,stateStack,font,"Please enter the name of the map to load. Do not include the .txt extension.", game_log){
    this->destination = destination;
}

void MapLoaderState::acceptString(){
    if(workingString.length() > 0 && workingString != "new"){
        std::ifstream instrm;
        instrm.open("maps/"+workingString+".txt");
        GameMap2* gm = new GameMap2();
        instrm >> *gm;
        
        //assign dstrects
        while(gm != nullptr){
            
            for(int r = 0; r < gm->getArrayDimensions().y; r++){
                for(int c = 0; c < gm->getArrayDimensions().x; c++){
                    gm->getBlock(c, r)->dstrect = {c*BLOCK_SIZE,BLOCK_SIZE*(gm->getArrayDimensions().y-r-1),BLOCK_SIZE,BLOCK_SIZE};
                }
            }
            if(gm->getNextMap() != nullptr){
                gm = gm->getNextMap();
            }
            else{
                break;
            }
        }
        while(gm->getPreviousMap() != nullptr){
            gm = gm->getPreviousMap();
        }
        
        removeSelfFromStateStack();
        
        GameState* nextState;
        switch(destination){
            case PLAY_GAME:
                nextState = new PlayGameState(game_renderer, game_window, game_timer, game_stateStack, game_font, gm, game_log);
                break;
            case MAP_EDITOR:
                nextState = new MapEditorState(game_renderer, game_window, game_timer, game_stateStack, game_font, gm, game_log);
                break;
            default: break;
        }
        game_stateStack->push(nextState);
    }
    else if(destination == MAP_EDITOR){
        removeSelfFromStateStack();
        GameState* nextState = new SetNewMapSizeState(game_renderer, game_window, game_timer, game_stateStack, game_font, game_log);
        game_stateStack->push(nextState);
    }
    else{
        //display error screen
        GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "You must enter a map name to load.", game_log);
        game_stateStack->push(nextState);
    }
    
}
