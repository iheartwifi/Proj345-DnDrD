//
//  CharacterPropertyChangerState.hpp
//  DnDrD
//
//  Created by oscar on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef CharacterPropertyChangerState_hpp
#define CharacterPropertyChangerState_hpp

#include <stdio.h>

#include <iostream>
#include "character.hpp"
#include "InputPromptState.hpp"

enum characterEditorButtons{
    C_NAME,
    C_STR,
    C_DEX,
    C_CON,
    C_INT,
    C_WIS,
    C_CHA,
    C_LVL
};

class CharacterPropertyChangerState : public InputPromptState{
private:
    character* characterToedit;
    characterEditorButtons buttonPressed;
public:
    CharacterPropertyChangerState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message, character* character, characterEditorButtons buttonPressed,GameLog* game_log);
    ~CharacterPropertyChangerState();
    
    void acceptString();
};


#endif /* CharacterPropertyChangerState_hpp */
