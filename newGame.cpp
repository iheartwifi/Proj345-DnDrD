//
//  newGame.cpp
//  DnDrD
//
//  Created by oscar on 2016-11-20.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "newGame.hpp"
using namespace std;

newGame::newGame(){
    initSDL();
    mainMenuInit();
    gameInit();
}
//load resources for game
void newGame::gameInit(){
    //delete all textures already in game_currentTextures
    for(int i = 0; i < game_rendererTextures.size(); i++){
        SDL_DestroyTexture(game_rendererTextures[i].texture);
    }
    game_rendererTextures.clear();
    
    //add textures to currentTextures one at a time
    {
        SDL_Surface*  addSurface = NULL;
        SDL_Texture* addTexture = NULL;
        
        SDL_Rect dstrect;
        //background image
        addSurface = IMG_Load("background.jpg");
        dstrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_rendererTextures.push_back(textureStruct{addTexture,dstrect});
        
        //hero image
        addSurface = IMG_Load("hero.png");
        dstrect = {0,0,0,0};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_rendererTextures.push_back(textureStruct{addTexture,dstrect});
        
        //ground STONE image
        addSurface = IMG_Load("ground.jpg");
        dstrect = {0,0,0,0};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_rendererTextures.push_back(textureStruct{addTexture,dstrect});
        
        //NPC image TESTING
        addSurface = IMG_Load("hero.png");
        dstrect = {0,0,0,0};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_rendererTextures.push_back(textureStruct{addTexture,dstrect});
    }
}

void newGame::play(){
    GameRenderer();
    GameInputHandler();
}
//Initialize SDL
void newGame::initSDL(){
    // Initiliaze SDL video and our timer.
    if (  SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER)  < 0){
        cerr << "Error in Init(). Could not initialize SDL." << endl;
    }
    
    //create game window
    game_window =  SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    //SDL_SetWindowFullscreen(game_window,SDL_WINDOW_FULLSCREEN);
    if(game_window == NULL){
        cerr << "Error in Init(). Could not create window." << endl;
    }
    else{
        //set backBuffer to window surface
        game_backBuffer = SDL_GetWindowSurface(game_window);
    }
    
    //create renderer
    renderer = SDL_GetRenderer(game_window);
    if(renderer == NULL){
        cerr << SDL_GetError() << endl;
    }
    
    //first start
    type=game_play;
    
}

//load resources for main menu
void newGame::mainMenuInit(){
    //delete all textures already in game_currentTextures
    for(int i = 0; i < game_currentTextures.size(); i++){
        SDL_DestroyTexture(game_currentTextures[i].texture);
    }
    game_currentTextures.clear();
    
    SDL_Surface*  addSurface = NULL;
    SDL_Texture* addTexture = NULL;
    //add textures to currentTextures one at a time
    {
        SDL_Rect dstrect;
        //background image
        addSurface = IMG_Load("background.jpg");
        dstrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
        
        //load buttons
        int i = 0;
        //new game button 1
        dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addSurface = IMG_Load("menu_buttons/main_newgame.png");
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture, dstrect});
        
        //map editor button 2
        dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addSurface = IMG_Load("menu_buttons/main_mapeditor.png");
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture, dstrect});
        
        //item editor button 3
        dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addSurface = IMG_Load("menu_buttons/main_item_editor.png");
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture, dstrect});
        
        //character editor button 4
        dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addSurface = IMG_Load("menu_buttons/main_character_editor.png");
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture, dstrect});
        
        //exit button
        dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addSurface = IMG_Load("menu_buttons/main_exit.png");
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
    }
}

void newGame::GameInputHandler(){
    switch(type){
        case main_menu:
            mainManuInputHandler();
            break;
        case game_play:
            break;
        default:
            break;
    }

}

void newGame::mainManuInputHandler(){
    //check for event
    while ( SDL_PollEvent(&game_event) )
    {
        //events for left mouse clicks
        if(game_event.type == SDL_MOUSEBUTTONDOWN && game_event.button.button == SDL_BUTTON_LEFT){
            //get current coordinates of mouse
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            
            //determine which button was pressed, if any
            int selection = 0;
            for(int i = 1; i < game_currentTextures.size(); i++){
                if(checkIfInside(game_currentTextures[i].dstrect, mouseX, mouseY)){
                    selection = i;
                }
            }
            switch (selection) {
                case 1:
                    this->type=game_play;
                    break;
                case 2:
                    int w,h;
                    cout<<"Please enter the weigth of the map"<<endl;
                    cin>>w;
                    cout<<"Please enter the height of the map"<<endl;
                    cin>>h;
                    this->type=map_editor;
                    break;
            }
        }
        //events for key presses
        if(game_event.type == SDL_KEYDOWN){
            switch (game_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    //emptyTextures();
                    this->quit=true;
                    break;
                default:
                    break;
            }
        }
    }
    return;

}

void newGame::GameRenderer(){
    switch(type){
        case main_menu:
            mainMenuRender();
            break;
        case game_play:
            break;
        case map_editor:
            break;
        default:
            break;
    }
}
void newGame::mapEditorRender(){
    SDL_Rect srcrect = {0,0,1773,1182};
    SDL_RenderCopy(renderer, game_currentTextures[0].texture, &srcrect, &game_currentTextures[0].dstrect);

}
void newGame::mainMenuRender(){
    //Render background
    SDL_Rect srcrect = {0,0,1773,1182};
    SDL_RenderCopy(renderer, game_currentTextures[0].texture, &srcrect, &game_currentTextures[0].dstrect);
    
    //Render buttons
    srcrect = {0,0,382,157};
    for(int i=1;i<game_currentTextures.size();i++){
        SDL_RenderCopy(renderer, game_currentTextures[i].texture, &srcrect, &game_currentTextures[i].dstrect);
    }
    
    //DO NOT PUT MORE CODE PAST HERE
    
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

//checks if given coordinates are inside a rectangle
bool newGame::checkIfInside(SDL_Rect dstrect, int x, int y){
    return (x >= dstrect.x &&
            x <= dstrect.x + dstrect.w &&
            y >= dstrect.y &&
            y <= dstrect.y + dstrect.h);
}
