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

class ItemEditorState : public GameState{
    
    ~ItemEditorState();
    void handleInput();
    void render();
public:
    ItemEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font);
};



#endif /* ItemEditorState_hpp */
