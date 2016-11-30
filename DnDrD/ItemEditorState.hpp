//
//  ItemEditorState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-29.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef ItemEditorState_hpp
#define ItemEditorState_hpp

#include <iostream>
#include "GameState.hpp"
#include <vector>
#include "Item.h"

class ItemEditorState : public GameState{
    
    Item* itemToEdit;
    
    ~ItemEditorState();
    void handleInput();
    void render();
    
    std::vector<std::string> description;
    void updateDescription();
    std::string descriptionToString();
    
    bool updated = true;
public:
    ItemEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, Item* item, GameLog* game_log);
};



#endif /* ItemEditorState_hpp */
