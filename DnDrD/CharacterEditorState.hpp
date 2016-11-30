//
//  CharacterEditorState.hpp
//  DnDrD
//
//  Created by oscar on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef CharacterEditorState_hpp
#define CharacterEditorState_hpp

#include <stdio.h>
#include <iostream>
#include "GameState.hpp"
#include <vector>
#include "character.hpp"
#include "CharacterPropertyChangerState.hpp"
class CharacterEditorState : public GameState{
    
    character* characterToEdit;
    
    ~CharacterEditorState();
    void handleInput();
    void render();
    
    std::vector<std::string> description;
    void updateDescription();
    std::string descriptionToString();
    
    bool updated = true;
public:
    CharacterEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, character* character,GameLog* game_log);
};

#endif /* CharacterEditorState_hpp */
