//
//  GameState.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include <vector>
#include <stack>
#include "defines.h"

//use struct to store textures. dstrect is optional
struct textureStruct{
    SDL_Texture* texture;
    SDL_Rect dstrect;
    SDL_Rect srcrect;
};

class GameState{
public:
    //game data
    SDL_Window* game_window;
    SDL_Renderer* game_renderer;
    int* game_timer; //controls framerate
    std::stack<GameState*>* game_stateStack;
    TTF_Font* game_font;
    
    //state data
    SDL_Event state_event; //receives user input
    std::vector<textureStruct> state_textures;
    
    //constructor
    GameState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font);
    //destructor, deletes only state data
    virtual ~GameState();
    
    virtual void handleInput() = 0;
    virtual void render() = 0;
    virtual void run();
    
    void endGame();
    bool checkIfInside(SDL_Rect dstrect, int x, int y);
    
    void removeSelfFromStateStack();
private:
    bool readyToDie = false; //This triggers object to delete itself at the end of run() if set to true
};

#endif /* GameState_hpp */
