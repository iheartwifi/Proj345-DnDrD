//
//  ItemEditorState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-29.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "ItemEditorState.hpp"
#include "GameState.hpp"
#include "ItemPropertyChangerState.hpp"
#include <fstream>

ItemEditorState::ItemEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, Item* item) : GameState(renderer,window,timer, stateStack, font){
    
    itemToEdit = item;
    
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
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //change type button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_TYPE);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //change str button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_STR);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //change dex button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_DEX);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change con button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_CON);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change int button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_INT);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change wis button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_WIS);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change cha button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_CHA);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change armour button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_ARMOUR);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        //change dmg button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_DMG);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //change atk button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_ATK);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
        //save button
        addSurface = IMG_Load(PATH_TO_ITEM_EDITOR_SAVE);
        addStruct.dstrect = {WINDOW_WIDTH/2 + (MENU_BUTTON_WIDTH)*(i/ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT)*(i++%ITEM_EDITOR_BUTTON_ROWS),
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addStruct.srcrect = {0,0, addSurface->w, addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        SDL_FreeSurface(addSurface);
        
        state_textures.push_back(addStruct);
        
    }
    
    updateDescription();
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
            GameState* nextState;
            switch (selection) {
                case 1:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter a name for your item.",itemToEdit, I_NAME);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 2:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter your item type.",itemToEdit, I_TYPE);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 3:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the strength bonus of your item.",itemToEdit, I_STR);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 4:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the dexterity bonus of your item.",itemToEdit, I_DEX);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 5:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the constitution bonus of your item.",itemToEdit, I_CON);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 6:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the intelligence bonus of your item.",itemToEdit, I_INT);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 7:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the wisdom bonus of your item.",itemToEdit, I_WIS);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 8:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the charisma bonus of your item.",itemToEdit, I_CHA);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 9:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the armour bonus of your item.",itemToEdit, I_ARM);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 10:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the damage bonus of your item.",itemToEdit, I_DMG);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 11:
                    nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter the attack bonus of your item.",itemToEdit, I_ATK);
                    game_stateStack->push(nextState);
                    updated = true;
                    break;
                case 12:
                    //do nothing
                    break;
                default:
                    break;
            }
            if(selection == 12){
                if(itemToEdit->validateItem()){
                    ofstream ostr;
                    ostr.open("items/"+itemToEdit->getName()+".txt");
                    ostr << *itemToEdit;
                    ostr.close();
                    
                    removeSelfFromStateStack();
                }
                else{
                    GameState *nextState = new MessageDisplayerState(game_renderer, game_window, game_timer, game_stateStack, game_font, "The item cannot be saved because it is not valid.");
                    game_stateStack->push(nextState);
                }
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
    //render working text
    if(updated){
        updated = false;
        for(int i = 0; i < state_textures.size(); i++){
            SDL_RenderCopy(game_renderer, state_textures[i].texture, &state_textures[i].srcrect, &state_textures[i].dstrect);
        }
        
        
        
        //make new texture from text
        updateDescription();
        SDL_Surface* addSurface = TTF_RenderText_Blended_Wrapped( game_font, descriptionToString().c_str(), COLOUR_WHITE, WINDOW_WIDTH/2 );
        SDL_Rect dstrect = {WINDOW_WIDTH/8,MENU_BUTTON_Y_OFFSET,addSurface->w,addSurface->h};
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(game_renderer, addSurface);
        
        //render text
        SDL_RenderCopy(game_renderer, textTexture, nullptr, &dstrect);
        
        //delete surface and texture
        SDL_FreeSurface(addSurface);
        SDL_DestroyTexture(textTexture);
        
        
        
        SDL_RenderPresent(game_renderer);
        SDL_RenderClear(game_renderer);
    }
    //this lets this state rerender itself when the state above it pops
    if(game_stateStack->top() != this){
        updated = true;
    }
}

std::string ItemEditorState::descriptionToString(){
    std::string returnString = "";
    for(int i = 0; i < description.size(); i++){
        returnString += description[i] + "\n";
    }
    return returnString;
}

void ItemEditorState::updateDescription(){
    //clear current description
    description.clear();
    
    //Set description
    {
        //get type
        std::string t;
        {
            switch(itemToEdit->getType()){
                case HELMET: t = "Helmet";
                    break;
                case ARMOR: t = "Armour";
                    break;
                case SHIELD: t = "Shield";
                    break;
                case RING: t = "Ring";
                    break;
                case BELT: t = "Belt";
                    break;
                case BOOTS: t = "Boots";
                    break;
                case WEAPON: t = "Weapon";
                    break;
                default:break;
            }
        }
        
        description.push_back("Name: " + itemToEdit->getName());
        description.push_back("Type: " + t);
        description.push_back("Strength: " + to_string(itemToEdit->getStr()));
        description.push_back("Dexterity: " + to_string(itemToEdit->getDex()));
        description.push_back("Constitution: " + to_string(itemToEdit->getCon()));
        description.push_back("Intelligence: " + to_string(itemToEdit->getIntel()));
        description.push_back("Wisdom: " + to_string(itemToEdit->getWis()));
        description.push_back("Charisma: " + to_string(itemToEdit->getCha()));
        description.push_back("Armour: " + to_string(itemToEdit->getArmor()));
        description.push_back("Damage: " + to_string(itemToEdit->getDmg()));
        description.push_back("Attack bonus: " + to_string(itemToEdit->getAtk()));
    }
}
