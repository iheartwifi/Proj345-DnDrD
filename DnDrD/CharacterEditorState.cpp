//
//  CharacterEditorState.cpp
//  DnDrD
//
//  Created by oscar on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "CharacterEditorState.hpp"

CharacterEditorState::CharacterEditorState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack, TTF_Font* font, character* character) : GameState(renderer,window,timer, stateStack, font){
    
    characterToEdit = character;
    
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
std::string CharacterEditorState::descriptionToString(){
    std::string returnString = "";
    for(int i = 0; i < description.size(); i++){
        returnString += description[i] + "\n";
    }
    return returnString;
}
void CharacterEditorState::updateDescription(){
    //clear current description
    description.clear();
    
    //Set description
    {
        //get type
        description.push_back("Name: " + characterToEdit->charName);
        description.push_back("Level: " + to_string(characterToEdit->level));
        
        description.push_back("Strength: " + to_string(characterToEdit->abilityScore[0]));
        description.push_back("Strength Modifier: " + to_string(characterToEdit->abilityModifier[0]));
        
        description.push_back("Dexterity: " + to_string(characterToEdit->abilityScore[1]));
        description.push_back("Dexterity Modifier: " + to_string(characterToEdit->abilityModifier[1]));
        description.push_back("Constitution: " + to_string(characterToEdit->abilityScore[2]));
        description.push_back("Constitution Modifier: " + to_string(characterToEdit->abilityModifier[2]));
        
        description.push_back("Intelligence: " + to_string(characterToEdit->abilityScore[3]));
        description.push_back("Intelligence Modifier: " + to_string(characterToEdit->abilityModifier[3]));
        
        description.push_back("Wisdom: " + to_string(characterToEdit->abilityScore[4]));
        description.push_back("Wisdom Modifier: " + to_string(characterToEdit->abilityModifier[4]));
        
        description.push_back("Charisma: " + to_string(characterToEdit->abilityScore[5]));
        description.push_back("Charisma Modifier: " + to_string(characterToEdit->abilityModifier[5]));
    }
}


CharacterEditorState::~CharacterEditorState(){
    //uses GameState destructor
    //
    //delete any additional resources here
}

void CharacterEditorState::render(){
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

void CharacterEditorState::handleInput(){
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
            /*nextState = new ItemPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter a name for your item.",itemToEdit, I_NAME);
            updated = true;
            game_stateStack->push(nextState);*/
            switch (selection) {
                case 1:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter a name for your character.",characterToEdit, C_NAME);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 2:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter new level for your character.",characterToEdit, C_LVL);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 3:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter new value for your character's strength.",characterToEdit, C_STR);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 4:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter new value for your character's dexterity.",characterToEdit, C_DEX);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 5:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter new value for your character's constitution.",characterToEdit, C_CON);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 6:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter new value for your character's intelligence.",characterToEdit, C_INT);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 7:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter new value for your character's wisdom.",characterToEdit, C_WIS);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 8:
                    nextState = new CharacterPropertyChangerState(game_renderer, game_window, game_timer, game_stateStack,game_font, "Please enter new value for your character's charisma.",characterToEdit, C_CHA);
                    updated = true;
                    game_stateStack->push(nextState);
                    break;
                case 9:
                    //RESERVE for ip
                    break;
                case 10:
                    //RESERVE for ic
                    break;
                case 11:
                    //do nothing
                    break;
                case 12:
                    //save and quit
                    break;
                default:
                    break;
            }
            if(selection == 12){
                characterToEdit->saveToFile();
                removeSelfFromStateStack();
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

