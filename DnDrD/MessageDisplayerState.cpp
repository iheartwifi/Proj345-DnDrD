//
//  TextInputState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "MessageDisplayerState.hpp"

MessageDisplayerState::MessageDisplayerState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message, GameLog* game_log) : GameState(renderer, window, timer, stateStack, font, game_log){
    
    this->game_font = font;
    this->messageToDisplay = message;
    
    SDL_Surface*  addSurface = NULL;
    SDL_Rect dstrect = {0,0,0,0};
    SDL_Rect srcrect = {0,0,0,0};
    
    textureStruct addStruct = {NULL, dstrect, srcrect};
    {
        //background image
        addSurface = IMG_Load(PATH_TO_BLANK_SCROLL);
        addStruct.dstrect = {WINDOW_WIDTH/2 - addSurface->w/2,(WINDOW_HEIGHT-addSurface->h)/2,addSurface->w,addSurface->h};
        addStruct.srcrect = {0,0,addSurface->w,addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //message text
        //the numbers given here to specify the size and location of the text should be changed to be more robust
        addSurface = TTF_RenderText_Blended_Wrapped( game_font, messageToDisplay.c_str(), COLOUR_BLACK, state_textures[0].dstrect.w - 200 );
        addStruct.dstrect = {(WINDOW_WIDTH - addSurface->w)/2,5*BLOCK_SIZE,addSurface->w,addSurface->h};
        addStruct.srcrect = {0,0,0,0};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
    }
    
    
}
void MessageDisplayerState::handleInput(){
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
void MessageDisplayerState::render(){
    SDL_RenderCopy(game_renderer, state_textures[0].texture, &state_textures[0].srcrect, &state_textures[0].dstrect);
    SDL_RenderCopy(game_renderer, state_textures[1].texture, nullptr, &state_textures[1].dstrect);
    
    SDL_RenderPresent(game_renderer);
    SDL_RenderClear(game_renderer);
}
