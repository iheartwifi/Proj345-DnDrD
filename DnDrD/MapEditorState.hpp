//
//  MapEditor.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef MapEditor_hpp
#define MapEditor_hpp

#include <stdio.h>
#include "vMapState.hpp"

class MapEditorState : public vMapState{
private:
    int AddSelection = 0;
    GameObject* addObject = nullptr;
    
public:
    MapEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, GameMap2* map);
    void handleInput();
    void render();
};

#endif /* MapEditor_hpp */
