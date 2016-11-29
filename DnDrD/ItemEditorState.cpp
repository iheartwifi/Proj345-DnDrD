//
//  ItemEditorState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-29.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "ItemEditorState.hpp"
#include "GameState.hpp"

ItemEditorState::ItemEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font) : GameState(renderer,window,timer, stateStack, font){
    
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
        //change name button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_NAME);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //change type button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_TYPE);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //change str button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_STR);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //change dex button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_DEX);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change con button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_CON);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change int button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_INT);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change wis button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_WIS);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change cha button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_CHA);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change armour button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_ARMOUR);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change dmg button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_DMG);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
    }
}
ItemEditorState::~ItemEditorState(){
    //uses GameState destructor
    //
    //delete any additional resources here
}
void ItemEditorState::handleInput(){
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
            switch (selection) {
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
void ItemEditorState::render(){
    for(int i = 0; i < state_textures.size(); i++){
        SDL_RenderCopy(game_renderer, state_textures[i].texture, &state_textures[i].srcrect, &state_textures[i].dstrect);
    }
    
//    //render working text
//    if(workingString.length() != 0){
//        //make new texture from text
//        SDL_Surface* addSurface = TTF_RenderText_Blended_Wrapped( game_font, workingString.c_str(), COLOUR_BLACK, 600 );
//        SDL_Rect dstrect = {(WINDOW_WIDTH - addSurface->w)/2,7*BLOCK_SIZE,addSurface->w,addSurface->h};
//        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
//        
//        //render text
//        SDL_RenderCopy(game_renderer, textTexture, nullptr, &dstrect);
//        
//        //delete surface and texture
//        SDL_FreeSurface(addSurface);
//        SDL_DestroyTexture(textTexture);
//    }

    
    SDL_RenderPresent(game_renderer);
    SDL_RenderClear(game_renderer);
}
