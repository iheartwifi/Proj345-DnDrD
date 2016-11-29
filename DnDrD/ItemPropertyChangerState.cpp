//
//  ItemPropertyChangerState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-29.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "ItemPropertyChangerState.hpp"
#include <sstream>

ItemPropertyChangerState::ItemPropertyChangerState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message, Item* item, itemEditorButtons buttonPressed) : InputPromptState(renderer, window, timer, stateStack, font, message){
    this->itemToEdit = item;
    this->buttonPressed = buttonPressed;
}
ItemPropertyChangerState::~ItemPropertyChangerState(){
    
}

void ItemPropertyChangerState::acceptString(){
    if(workingString == ""){
        GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "You must enter a value.");
        game_stateStack->push(nextState);
    }
    else{
        std::stringstream str(workingString);
        int val;
        str >> val;
        
        switch(buttonPressed){
            case I_NAME:
                itemToEdit->setName(workingString);
                break;
            case I_TYPE:
                if(workingString == "none"){
                    itemToEdit->setType(I_NONE);
                }
                else if(workingString == "helmet"){
                    itemToEdit->setType(HELMET);
                }
                else if(workingString == "armour" || workingString == "armor"){
                    itemToEdit->setType(ARMOR);
                }
                else if(workingString == "shield"){
                    itemToEdit->setType(SHIELD);
                }
                else if(workingString == "ring"){
                    itemToEdit->setType(RING);
                }
                else if(workingString == "belt"){
                    itemToEdit->setType(BELT);
                }
                else if(workingString == "boots"){
                    itemToEdit->setType(BOOTS);
                }
                else if(workingString == "weaopn"){
                    itemToEdit->setType(WEAPON);
                }
                break;
            case I_STR:
                itemToEdit->setStr(val);
                break;
            case I_DEX:
                itemToEdit->setDex(val);
                break;
            case I_CON:
                itemToEdit->setCon(val);
                break;
            case I_INT:
                itemToEdit->setIntel(val);
                break;
            case I_WIS:
                itemToEdit->setWis(val);
                break;
            case I_CHA:
                itemToEdit->setCha(val);
                break;
            case I_ARM:
                itemToEdit->setArmor(val);
                break;
            case I_DMG:
                itemToEdit->setDmg(val);
                break;
            case I_ATK:
                itemToEdit->setAtk(val);
                break;
            default:
                break;
        }
        removeSelfFromStateStack();
        
    }
}
