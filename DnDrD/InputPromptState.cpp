//
//  InputPromptState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-25.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "InputPromptState.hpp"
int InputPromptState::numberInitialized  = 0;

InputPromptState::InputPromptState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, std::string message) :
MessageDisplayerState(renderer, window, timer, stateStack, font, message){
    this->workingString = "";
    SDL_StartTextInput();
    numberInitialized++;
}
InputPromptState::~InputPromptState(){
    if(--numberInitialized == 0){
        SDL_StopTextInput();
    }
}

void InputPromptState::handleInput(){
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
            //if statement handles key presses with mac command key
            if(SDL_GetModState() & KMOD_GUI){
                if(state_event.key.keysym.sym == SDLK_c){
                    SDL_SetClipboardText(workingString.c_str());
                }
                else if(state_event.key.keysym.sym == SDLK_v){
                    workingString = SDL_GetClipboardText();
                    textHasBeenUpdated = true;
                }
            }
            //else handle other key presses
            else{
                switch (state_event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        removeSelfFromStateStack();
                        break;
                    case SDLK_BACKSPACE:
                        if(workingString.length() > 0){
                            workingString.pop_back();
                            textHasBeenUpdated = true;
                        }
                        break;
                    case SDLK_RETURN:
                        acceptString();
                        textHasBeenUpdated = true;
                        break;
                    default:
                        break;
                }
            }
            
        }
        else if(state_event.type == SDL_TEXTINPUT){
            workingString += state_event.text.text;
            textHasBeenUpdated = true;
        }
    }
    return;
}
void InputPromptState::render(){
    //only rerender if text has been updated.
    if(textHasBeenUpdated){
        textHasBeenUpdated = false;
        //render scroll and prompt text
        SDL_RenderCopy(game_renderer, state_textures[0].texture, &state_textures[0].srcrect, &state_textures[0].dstrect);
        SDL_RenderCopy(game_renderer, state_textures[1].texture, nullptr, &state_textures[1].dstrect);
        
        //render working text
        if(workingString.length() != 0){
            //make new texture from text
            SDL_Surface* addSurface = TTF_RenderText_Blended_Wrapped( game_font, workingString.c_str(), COLOUR_BLACK, 600 );
            SDL_Rect dstrect = {(WINDOW_WIDTH - addSurface->w)/2,7*BLOCK_SIZE,addSurface->w,addSurface->h};
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
            
            //render text
            SDL_RenderCopy(game_renderer, textTexture, nullptr, &dstrect);
            
            //delete surface and texture
            SDL_FreeSurface(addSurface);
            SDL_DestroyTexture(textTexture);
        }
        
        
        SDL_RenderPresent(game_renderer);
        SDL_RenderClear(game_renderer);
    }
    
    //this lets this state rerender itself when the state above it pops
    if(game_stateStack->top() != this){
        textHasBeenUpdated = true;
    }
}
void InputPromptState::acceptString(){
    removeSelfFromStateStack();
}
