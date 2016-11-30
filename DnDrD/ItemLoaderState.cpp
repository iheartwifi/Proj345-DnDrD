//
//  ItemLoaderState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-29.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "ItemLoaderState.hpp"
#include "Item.h"
#include <fstream>
#include "ItemEditorState.hpp"

ItemLoaderState::ItemLoaderState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, int destination, GameLog* game_log) : InputPromptState(renderer,window,timer,stateStack,font,"Please enter the name of the item to load. Do not include the .txt extension.", game_log){
    this->destination = destination;
}

void ItemLoaderState::acceptString(){
    if(workingString.length() > 0){
        Item* i = new Item;
        
        if(workingString == "new"){
            i = new Item();
        }
        else{
            std::ifstream instrm;
            instrm.open("items/" + workingString + ".txt");
            instrm >> *i;
        }
        
        removeSelfFromStateStack();
        
        GameState* nextState;
        switch(destination){
            case ITEM_EDITOR:
                nextState = new ItemEditorState(game_renderer, game_window, game_timer, game_stateStack, game_font, i, game_log);
                break;
            case CHAR_EDITOR:
                /*
                 
                 */
                break;
            default: break;
        }
        game_stateStack->push(nextState);
    }
    else{
        //display error screen
        GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "You must enter an item name to load.", game_log);
        game_stateStack->push(nextState);
    }
    
}

