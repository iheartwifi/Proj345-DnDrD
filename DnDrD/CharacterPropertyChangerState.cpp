//
//  CharacterPropertyChangerState.cpp
//  DnDrD
//
//  Created by oscar on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "CharacterPropertyChangerState.hpp"
#include <sstream>

CharacterPropertyChangerState::CharacterPropertyChangerState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message, character* character, characterEditorButtons buttonPressed) : InputPromptState(renderer, window, timer, stateStack, font, message){
    this->characterToedit = character;
    this->buttonPressed = buttonPressed;
}
CharacterPropertyChangerState::~CharacterPropertyChangerState(){
    
}

void CharacterPropertyChangerState::acceptString(){
    int temp=0;
    if(workingString == ""){
        GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "You must enter a value.");
        game_stateStack->push(nextState);
    }
    else{
        std::stringstream str(workingString);
        int val;
        str >> val;
        
        switch(buttonPressed){
            case C_NAME:
                characterToedit->setNewName(workingString);
                break;
            case C_STR:
                characterToedit->abilityScore[0]=val;
                characterToedit->calculateAbility();
                break;
            case C_DEX:
                characterToedit->abilityScore[1]=val;
                characterToedit->calculateAbility();
                break;
            case C_CON:
                characterToedit->abilityScore[2]=val;
                characterToedit->calculateAbility();
                break;
            case C_INT:
                characterToedit->abilityScore[3]=val;
                characterToedit->calculateAbility();
                break;
            case C_WIS:
                characterToedit->abilityScore[4]=val;
                characterToedit->calculateAbility();
                break;
            case C_CHA:
                characterToedit->abilityScore[5]=val;
                characterToedit->calculateAbility();
                break;
            case C_LVL:
            {
                temp=val-characterToedit->level;
                if(temp>=0){
                    for(int i=0;i<temp;i++)
                        characterToedit->reCalLevelUp();
                }
                else{
                    for(int i=0;i<temp;i++)
                        characterToedit->reCalLevelDown();
                }
                characterToedit->level=val;
            }
                break;
            default:
                break;
        }
        removeSelfFromStateStack();
        
    }
}
