//
//  main.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-11.
//  Copyright © 2016 COMP 345. All rights reserved.
//
//

#include <iostream>
#include <stack>
#include <vector>
#include "defines.h"
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "GameState.hpp"
#include "MainMenuState.hpp"

using namespace std;

//---game data
stack<GameState*>* game_stateStack;
SDL_Window* game_window;
SDL_Renderer* game_renderer;
int game_timer; //for controlling framerate
TTF_Font* game_font;

//fuctions to start and stop SDL
void initSDL();
void closeSDL();

int main(int argc, const char * argv[]) {
    
    initSDL();
    while(!game_stateStack->empty()){
        
        game_stateStack->top()->run();
        
    }
    
    closeSDL();
    
    return 0;
}

//Initialize SDL
void initSDL(){
    // Initiliaze SDL video and our timer.
    if (  SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER)  < 0){
        cerr << "Error in Init(). Could not initialize SDL." << endl;
    }
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
    }
    game_font = TTF_OpenFont(PATH_TO_FONT, FONT_SIZE);
    
    //create game window
    game_window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(game_window == NULL){
        cerr << "Error in Init(). Could not create window." << endl;
    }
    
    //create renderer
    game_renderer = SDL_CreateRenderer(game_window, -1 , SDL_RENDERER_ACCELERATED);
    if(game_renderer == NULL){
        cerr << SDL_GetError() << endl;
    }
    
    //initialize state stack
    game_stateStack = new stack<GameState*>;
    
    //push main menu onto stack
    game_stateStack->push(new MainMenuState(game_renderer, game_window, &game_timer, game_stateStack, game_font));
    
    //set the game timer
    game_timer = SDL_GetTicks();
    
}
//Close SDL
void closeSDL(){
    
    //Destroy window
    SDL_DestroyWindow( game_window );
    game_window = NULL;
    
    //Quit SDL
    SDL_Quit();
}
