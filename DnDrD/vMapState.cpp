//
//  vMapState.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-24.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "vMapState.hpp"

vMapState::vMapState(SDL_Renderer* renderer, SDL_Window* window, int* timer, std::stack<GameState*>* stateStack) : GameState(renderer,window,timer, stateStack){
    
    //load default map and hero
    //TODO: allow specific map & hero to be loaded
    {
        state_map = new GameMap2(15, 15, Coordinate {0,0}, Coordinate {14,14}, nullptr, nullptr);
        state_hero = new Hero();
        state_map->occupyBlock(Coordinate{4,6}, state_hero);
            state_map->fillcell(Coordinate{0, 14}, GRASS);
            state_map->fillcell(Coordinate{0, 13}, WALL);
            state_map->fillcell(Coordinate{0, 12}, WATER);
    }
    
    //set initial dstrect of each block
    for(int r = 0; r < state_map->getArrayDimensions().y; r++){
        for(int c = 0; c < state_map->getArrayDimensions().x; c++){
            state_map->getBlock(c, r)->dstrect = {c*BLOCK_SIZE,BLOCK_SIZE*(state_map->getArrayDimensions().y-r-1),BLOCK_SIZE,BLOCK_SIZE};
        }
    }

    
    SDL_Surface*  addSurface = NULL;
    SDL_Rect dstrect = {0,0,0,0};
    SDL_Rect srcrect = {0,0,0,0};
    
    textureStruct addStruct = {NULL, dstrect, srcrect};
    
    //add textures to currentTextures one at a time
    {
        //hero image
        addSurface = IMG_Load("hero.png");
        addStruct.dstrect = {0,0,0,0};
        addStruct.srcrect = {0,0,HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE};
        addStruct.texture = SDL_CreateTextureFromSurface(renderer, addSurface);
        state_textures.push_back(addStruct);
        
        //load textures for ground types
        int i = 0;
        //ground STONE image
        addSurface = IMG_Load("ground.jpg");
        addStruct.dstrect = {BLOCK_SIZE * i++,WINDOW_HEIGHT-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE};
        addStruct.srcrect = {STONE_GROUND_X_SELECTION,STONE_GROUND_Y_SELECTION,STONE_GROUND_SIZE,STONE_GROUND_SIZE};
        addStruct.texture = SDL_CreateTextureFromSurface(renderer, addSurface);
        state_textures.push_back(addStruct);
        
        //ground grass image
        addSurface = IMG_Load("grass.png");
        addStruct.dstrect = {BLOCK_SIZE * i++,WINDOW_HEIGHT-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE};
        addStruct.srcrect = {0,0,addSurface->w,addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(renderer, addSurface);
        state_textures.push_back(addStruct);
        
        //ground wall image
        addSurface = IMG_Load("wall.png");
        addStruct.dstrect = {BLOCK_SIZE * i++,WINDOW_HEIGHT-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE};
        addStruct.srcrect = {0,0,addSurface->w,addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(renderer, addSurface);
        state_textures.push_back(addStruct);
        
        //ground water image
        addSurface = IMG_Load("water.png");
        addStruct.dstrect = {BLOCK_SIZE * i++,WINDOW_HEIGHT-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE};
        addStruct.srcrect = {0,0,addSurface->w,addSurface->h};
        addStruct.texture = SDL_CreateTextureFromSurface(renderer, addSurface);
        state_textures.push_back(addStruct);
        
        state_textures.push_back(addStruct);
    }
    
    SDL_FreeSurface(addSurface);
    
}
vMapState::~vMapState(){
    delete state_map;
    delete state_hero;
}
void vMapState::render(){
        for(int r = 0; r < state_map->getArrayDimensions().y; r++){
            for(int c = 0; c < state_map->getArrayDimensions().x; c++){
                //if statement makes game render map only if it is in the window and game area; improves performance greatly
                //
                if(state_map->getBlock(c, r)->dstrect.x >= 0 &&
                   state_map->getBlock(c, r)->dstrect.y >= 0 &&
                   state_map->getBlock(c, r)->dstrect.x < WINDOW_WIDTH &&
                   state_map->getBlock(c, r)->dstrect.y + state_map->getBlock(c, r)->dstrect.h <= WINDOW_HEIGHT - TOOLBAR_PANE_HEIGHT){
    
                    //determine which texture to display for ground type
                    int texType = 0;
                    switch (state_map->getBlock(c, r)->getGroundType()) {
                        case STONE:
                            texType = 1;
                            break;
                        case GRASS:
                            texType = 2;
                            break;
                        case WALL:
                            texType = 3;
                            break;
                        case WATER:
                            texType = 4;
                            break;
                        default:
                            break;
                    }
                    //render ground of block
                    SDL_RenderCopy(game_renderer, state_textures[texType].texture, &state_textures[texType].srcrect, &state_map->getBlock(c, r)->dstrect);
    
                    //TODO: Render stuff contained by block
    
                    //render hero
                    if(state_hero != NULL && state_map->getBlock(c, r)->getContainedItem() == state_hero){
                        state_textures[0].srcrect = {state_hero->getMoveCounter()*HERO_IMAGE_SPRITE_SIZE,state_hero->getOrientation()*HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE};
                        SDL_RenderCopy(game_renderer, state_textures[0].texture, &state_textures[0].srcrect, &state_map->getBlock(c, r)->dstrect);
                    }
    
                }
            }
        }
    
        //Draw a grey area for the toolbar
        {
            //set location and size of toolbar
            SDL_Rect toolbarPane = {0,WINDOW_HEIGHT-TOOLBAR_PANE_HEIGHT,WINDOW_WIDTH,TOOLBAR_PANE_HEIGHT};
            //Set the render colour for the toolbar area
            SDL_SetRenderDrawColor(game_renderer, 150, 150, 150, 255);
            //draw the rectangle
            SDL_RenderFillRect(game_renderer, &toolbarPane);
            //reset render colour to black
            SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 255);
        }
}

void vMapState::shiftMap(Orientation direction){
    int xShift = 0;
    int yShift = 0;
    switch(direction){
        case ORIENTATION_UP:
            yShift = -BLOCK_SIZE;
            break;
        case ORIENTATION_DOWN:
            yShift = BLOCK_SIZE;
            break;
        case ORIENTATION_RIGHT:
            xShift = BLOCK_SIZE;
            break;
        case ORIENTATION_LEFT:
            xShift = -BLOCK_SIZE;
            break;
    }
    for(int r = 0; r < state_map->getArrayDimensions().y; r++){
        for(int c = 0; c < state_map->getArrayDimensions().x; c++){
            state_map->getBlock(c, r)->dstrect.x += xShift;
            state_map->getBlock(c, r)->dstrect.y += yShift;
        }
    }
}
