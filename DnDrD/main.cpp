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

#include "GameState.hpp"
#include "MainMenuState.hpp"

using namespace std;



//---game data
stack<GameState*>* game_stateStack;
SDL_Window* game_window;
SDL_Renderer* game_renderer;
int game_timer; //for controlling framerate

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
    game_stateStack->push(new MainMenuState(game_renderer, game_window, &game_timer, game_stateStack));
    
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


////render the mapEditor
//void mapEditor(){
//    //if game_currentTextures is not initialized
//    if(game_currentTextures.empty()){
//        //remove current method from state stack
//        game_stateStack.pop();
//
//        //add initialization method to state stack
//        stateStruct state;
//        state.stateMethod = mapEditorInit;
//        game_stateStack.push(state);
//
//        //break to initialize. Will return
//        return;
//    }
//    //limit frame rate to FRAME_RATE
//    if ( (SDL_GetTicks() - game_timer) >= FRAME_RATE )
//    {
//        mapEditorInputHandler();
//        //ALL RENDERING CODE TAKES PLACE IN HERE
//        {
//            renderMap();
//
//            SDL_Rect dstrect = {0,0,0,0};
//            SDL_Rect srcrect = {0,0,0,0};
//            for(int i = 2; i < 6;i++){
//                srcrect = game_currentTextures[i].srcrect;
//                dstrect = {BLOCK_SIZE * (i-2),WINDOW_HEIGHT-TOOLBAR_PANE_HEIGHT,BLOCK_SIZE,BLOCK_SIZE};
//                SDL_RenderCopy(renderer, game_currentTextures[i].texture, &srcrect, &dstrect);
//            }
//
//        }
//        //DO NOT PUT MORE CODE PAST HERE
//
//        SDL_RenderPresent(renderer);
//        SDL_RenderClear(renderer);
//
//        //part of framerate limiter
//        game_timer = SDL_GetTicks();
//    }
//    else{
//        //Wait remaining time
//        SDL_Delay( FRAME_RATE - (SDL_GetTicks() - game_timer) + 1 );
//    }
//}
