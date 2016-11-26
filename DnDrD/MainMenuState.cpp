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
#include "MessageDisplayerState.hpp"
#include "InputPromptState.hpp"

MainMenuState::MainMenuState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font) : GameState(renderer,window,timer, stateStack, font){
    SDL_Surface*  addSurface = NULL;
    SDL_Rect dstrect = {0,0,0,0};
    SDL_Rect srcrect = {0,0,0,0};
    
    textureStruct addStruct = {NULL, dstrect, srcrect};
    
    //add textures to currentTextures one at a time
    {
        //background image
        addSurface = IMG_Load(PATH_TO_BACKGROUND);
        addStruct.dstrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
        addStruct.srcrect = {0,0,addSurface->w,addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //load buttons
        int i = 0;
        //new game button
        addSurface = IMG_Load(PATH_TO_MAIN_MENU_BUTTON_NEW_GAME);
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //map editor button
        addSurface = IMG_Load(PATH_TO_MAIN_MENU_BUTTON_MAP_EDITOR);
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //character editor button
        addSurface = IMG_Load(PATH_TO_MAIN_MENU_BUTTON_CHARACTER_EDITOR);
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //item editor button
        addSurface = IMG_Load(PATH_TO_MAIN_MENU_BUTTON_ITEM_EDITOR);
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //exit button
        addSurface = IMG_Load(PATH_TO_MAIN_MENU_BUTTON_EXIT);
        addStruct.dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
    }
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
                    nextState = new PlayGameState(game_renderer,game_window,game_timer,game_stateStack, game_font);
                    game_stateStack->push(nextState);
                    break;
                case 2:
                    nextState = new MapEditorState(game_renderer,game_window,game_timer,game_stateStack, game_font);
                    game_stateStack->push(nextState);
                    break;
                case 3:
                    //TODO: add character editor
                    
                    nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "Example Message: The map file given was either not found or was invalid.");
                    game_stateStack->push(nextState);
                    break;
                case 4:
                    //TODO: add item editor
                    
                    nextState = new InputPromptState(game_renderer, game_window, game_timer, game_stateStack, game_font, "Please enter the name of the item you wish to edit or enter 'new' to create a new item.");
                    game_stateStack->push(nextState);
                    break;
                case 5:
                    endGame();
                    break;
                default:
                    break;
            }
        }
        //events for key presses
        if(state_event.type == SDL_KEYDOWN){
            switch (state_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    removeSelfFromStateStack();
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
