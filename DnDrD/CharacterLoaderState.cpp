//
//  CharacterLoaderState.cpp
//  DnDrD
//
//  Created by oscar on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "CharacterLoaderState.hpp"


#include "ItemLoaderState.hpp"
#include "character.hpp"
#include <fstream>
#include "CharacterEditorState.hpp"
#include "ItemEditorState.hpp"

CharacterLoaderState::CharacterLoaderState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, int destination) : InputPromptState(renderer,window,timer,stateStack,font,"Please enter the name of the character to load. Do not include the .txt extension.", game_log){
    this->destination = destination;
}

void CharacterLoaderState::acceptString(){
    if(workingString.length() > 0){
        character* i = new character;
        
        if(workingString == "new"){
            i = new character();
        }
        else{
            i->LoadFromFile(workingString);
        }
        
        removeSelfFromStateStack();
        
        GameState* nextState;
        switch(destination){
            case ITEM_EDITOR:
               /*nextState = new ItemEditorState(game_renderer, game_window, game_timer, game_stateStack, game_font, i);*/
                break;
            case CHAR_EDITOR:
                nextState = new CharacterEditorState(game_renderer, game_window, game_timer, game_stateStack, game_font, i, game_log);
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

