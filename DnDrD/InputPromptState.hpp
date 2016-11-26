//
//  InputPromptState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-25.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef InputPromptState_hpp
#define InputPromptState_hpp

#include <stdio.h>
#include "MessageDisplayerState.hpp"

class InputPromptState : public MessageDisplayerState{
private:
    std::string workingString;
    bool textHasBeenUpdated = true;
public:
    InputPromptState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message);
    ~InputPromptState();
    void handleInput();
    void render();
    
};



#endif /* InputPromptState_hpp */
