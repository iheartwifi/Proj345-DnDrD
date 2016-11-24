//
//  MainMenuState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "MainMenuState.hpp"
#include "PlayGameState.hpp"
#include "MapEditorState.hpp"

MainMenuState::MainMenuState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack) : GameState(renderer,window,timer, stateStack){
    SDL_Surface*  addSurface = NULL;
    SDL_Rect dstrect = {0,0,0,0};
    SDL_Rect srcrect = {0,0,0,0};
    
    textureStruct addStruct = {NULL, dstrect, srcrect};
    
    //add textures to currentTextures one at a time
    {
        //background image
        addSurface = IMG_Load("background.jpg");
        addStruct.dstrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
        addStruct.srcrect = {0,0,addSurface->w,addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        
        state_textures.push_back(addStruct);
        
        //load buttons
        int i = 0;
        //new game button
        addSurface = IMG_Load("menu_buttons/main_newgame.png");
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);

        state_textures.push_back(addStruct);
        
        //map editor button
        //new game button
        addSurface = IMG_Load("menu_buttons/main_mapeditor.png");
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        
        state_textures.push_back(addStruct);
        
        //exit button
        //new game button
        addSurface = IMG_Load("menu_buttons/main_exit.png");
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        
        state_textures.push_back(addStruct);
    }
    
    SDL_FreeSurface(addSurface);
}
MainMenuState::~MainMenuState(){
    //uses GameState destructor
    //
    //delete any additional resources here
}
void MainMenuState::handleInput(){
    //check for event
    while ( SDL_PollEvent(&state_event) )
    {
        //quit game when window exit button is pressed
        if (state_event.type == SDL_QUIT)
        {
            endGame();
        }
        //events for left mouse clicks
        if(state_event.type == SDL_MOUSEBUTTONDOWN && state_event.button.button == SDL_BUTTON_LEFT){
            //get current coordinates of mouse
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            
            //determine which button was pressed, if any
            int selection = 0;
            for(int i = 1; i < state_textures.size(); i++){
                if(checkIfInside(state_textures[i].dstrect, mouseX, mouseY)){
                    selection = i;
                }
            }
            GameState* nextState = NULL;
            switch (selection) {
                case 1:
                    nextState = new PlayGameState(game_renderer,game_window,game_timer,game_stateStack);
                    game_stateStack->push(nextState);
                    break;
                case 2:
                    nextState = new MapEditorState(game_renderer,game_window,game_timer,game_stateStack);
                    game_stateStack->push(nextState);
                    break;
                case 3:
                    endGame();
                    break;
            }
        }
        //events for key presses
        if(state_event.type == SDL_KEYDOWN){
            switch (state_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    //pop self off stack
                    game_stateStack->pop();
                    
                    //delete this;
                    
                    break;
                default:
                    break;
            }
        }
    }
    return;
}
void MainMenuState::render(){
    for(int i = 0; i < state_textures.size(); i++){
        SDL_RenderCopy(game_renderer, state_textures[i].texture, &state_textures[i].srcrect, &state_textures[i].dstrect);
    }
    
    SDL_RenderPresent(game_renderer);
    SDL_RenderClear(game_renderer);
}
