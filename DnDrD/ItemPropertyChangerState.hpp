//
//  ItemPropertyChangerState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-29.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef ItemPropertyChangerState_hpp
#define ItemPropertyChangerState_hpp

#include <iostream>
#include "Item.h"
#include "InputPromptState.hpp"

enum itemEditorButtons{
    I_NAME,
    I_TYPE,
    I_STR,
    I_DEX,
    I_CON,
    I_INT,
    I_WIS,
    I_CHA,
    I_ARM,
    I_DMG,
    I_ATK
};

class ItemPropertyChangerState : public InputPromptState{
private:
    Item* itemToEdit;
    itemEditorButtons buttonPressed;
public:
    ItemPropertyChangerState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message, Item* item, itemEditorButtons buttonPressed);
    ~ItemPropertyChangerState();
    
    void acceptString();
};

#endif /* ItemPropertyChangerState_hpp */
