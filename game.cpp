//
//  game.cpp
//  DnDrD
//
//  Created by oscar on 2016-11-17.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "game.hpp"
void game(){
    
};

void game::gameInputHandler(){
    //check for event
    while ( SDL_PollEvent(&game_event) )
    {
        //quit game when window exit button is pressed
        if (game_event.type == SDL_QUIT)
        {
            endGame();
        }
        if(game_event.type == SDL_MOUSEBUTTONDOWN && game_event.button.button == SDL_BUTTON_LEFT){
            
        }
        if(game_event.type == SDL_KEYDOWN){
            switch (game_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    //pop self off stack
                    game_stateStack.pop();
                    
                    //clear textures vector
                    emptyTextures();
                    
                    break;
                case SDLK_w:
                    moveHero(ORIENTATION_UP);
                    break;
                case SDLK_s:
                    moveHero(ORIENTATION_DOWN);
                    break;
                case SDLK_a:
                    moveHero(ORIENTATION_LEFT);
                    break;
                case SDLK_d:
                    moveHero(ORIENTATION_RIGHT);
                    break;
                case SDLK_UP:
                    shiftMap(ORIENTATION_UP);
                    break;
                case SDLK_DOWN:
                    shiftMap(ORIENTATION_DOWN);
                    break;
                case SDLK_LEFT:
                    shiftMap(ORIENTATION_LEFT);
                    break;
                case SDLK_RIGHT:
                    shiftMap(ORIENTATION_RIGHT);
                    break;
                default:
                    break;
            }
        }
    }
}

//load resources for game
void game::gameInit(){
    //delete all textures already in game_currentTextures
    for(int i = 0; i < game_currentTextures.size(); i++){
        SDL_DestroyTexture(game_currentTextures[i].texture);
    }
    game_currentTextures.clear();
    
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
        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
        
        //hero image
        addSurface = IMG_Load("hero.png");
        dstrect = {0,0,0,0};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
        
        //ground STONE image
        addSurface = IMG_Load("ground.jpg");
        dstrect = {0,0,0,0};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
        
        //NPC image TESTING
        addSurface = IMG_Load("hero.png");
        dstrect = {0,0,0,0};
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
    }
    
    //delete gamemap in case one already existed
    delete game_map;
    //create gamemap TODO: allow map to be loaded
    game_map = new GameMap2(30,30,Coordinate{0,0},Coordinate{19,14},nullptr, nullptr);
    //set initial dstrect of each block
    for(int r = 0; r < game_map->getArrayDimensions().y; r++){
        for(int c = 0; c < game_map->getArrayDimensions().x; c++){
            game_map->getBlock(c, r)->dstrect = {c*BLOCK_SIZE,BLOCK_SIZE*(game_map->getArrayDimensions().y-r-1),BLOCK_SIZE,BLOCK_SIZE};
        }
    }
    
    //create hero TODO: allow char to be loaded
    game_hero = new Hero();
    //add hero to map
    game_map->occupyBlock(Coordinate{4,18}, game_hero);
    
    //TEST GU
    game_NPC = new NPC();
    //add hero to map
    game_map->occupyBlock(Coordinate{4,25}, game_NPC);
    game_NPC->getMiniMap(Coordinate{4,25});
    SDL_GetWindowSize(game_window,&w,&h);
    
    TTF_Init();
    //gametype
    type=game_play;
}

//load resources for main menu
void game::mainMenuInit(){
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
        //new game button
        dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2,
            MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,
            MENU_BUTTON_WIDTH,
            MENU_BUTTON_HEIGHT};
        addSurface = IMG_Load("menu_buttons/main_newgame.png");
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture, dstrect});
        
        //exit button
        dstrect = {WINDOW_WIDTH/2 - MENU_BUTTON_WIDTH/2, MENU_BUTTON_Y_OFFSET + (MENU_BUTTON_HEIGHT+MENU_BUTTON_SPACING)*i++,MENU_BUTTON_WIDTH,MENU_BUTTON_HEIGHT};
        addSurface = IMG_Load("menu_buttons/main_exit.png");
        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
        SDL_FreeSurface(addSurface);
        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
    }
}

void game::mainMenuInputHandler(){
    //check for event
    while ( SDL_PollEvent(&game_event) )
    {
        //quit game when window exit button is pressed
        if (game_event.type == SDL_QUIT)
        {
            endGame();
        }
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
            stateStruct nextState;
            switch (selection) {
                case 1:
                    this->type=game_play;
                    break;
                case 2:
                    endGame();
                    break;
            }
        }
        //events for key presses
        if(game_event.type == SDL_KEYDOWN){
            switch (game_event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    endGame();
                    emptyTextures();
                    
                    break;
                default:
                    break;
            }
        }
    }
    return;
}

void game::mainMenu(){
    //if game_currentTextures is not initialized
    if(game_currentTextures.empty()){
        //remove current method from state stack
        game_stateStack.pop();
        
        //add initialization method to state stack
        stateStruct state;
        state.stateMethod = mainMenuInit;
        game_stateStack.push(state);
        
        //break to initialize. Will return
        return;
    }
    //limit frame rate to FRAME_RATE
    if ( (SDL_GetTicks() - game_timer) >= FRAME_RATE )
    {
        mainMenuInputHandler();
        //ALL RENDERING CODE TAKES PLACE IN HERE
        {
            //Render background
            SDL_Rect srcrect = {0,0,1773,1182};
            SDL_RenderCopy(renderer, game_currentTextures[0].texture, &srcrect, &game_currentTextures[0].dstrect);
            
            //Render buttons
            srcrect = {0,0,382,157};
            SDL_RenderCopy(renderer, game_currentTextures[1].texture, &srcrect, &game_currentTextures[1].dstrect);
            srcrect = {0,0,382,157};
            SDL_RenderCopy(renderer, game_currentTextures[2].texture, &srcrect, &game_currentTextures[2].dstrect);
        }
        //DO NOT PUT MORE CODE PAST HERE
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        
        //part of framerate limiter
        game_timer = SDL_GetTicks();
    }
    else{
        //Wait remaining time
        SDL_Delay( FRAME_RATE - (SDL_GetTicks() - game_timer) + 1 );
    }
}

//render the game screen
void game::playgame(){
    //if game_currentTextures is not initialized
    if(game_currentTextures.empty()){
        //remove current method from state stack
        game_stateStack.pop();
        
        //add initialization method to state stack
        stateStruct state;
        state.stateMethod = gameInit;
        game_stateStack.push(state);
        
        //break to initialize. Will return
        return;
    }
    //limit frame rate to FRAME_RATE
    if ( (SDL_GetTicks() - game_timer) >= FRAME_RATE )
    {
        //ALL RENDERING CODE TAKES PLACE IN HERE
        {
            game_NPC->HeroDect(game_hero);
            switch(type){
                case playing:
                    gameInputHandler();
                    renderMap();
                    game_NPC->Move(game_map,game_hero);
                    break;
                case combat:
                    Sans = TTF_OpenFont("Pacifico.ttf", 90);
                    renderCombetScen();
                    TTF_CloseFont(Sans);
                    break;
            }
        }
        //DO NOT PUT MORE CODE PAST HERE
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        
        //part of framerate limiter
        game_timer = SDL_GetTicks();
    }
    else{
        //Wait remaining time
        SDL_Delay( FRAME_RATE - (SDL_GetTicks() - game_timer) + 1 );
        cout << 1000/(SDL_GetTicks() - game_timer) << endl;
    }
}

void game::renderMap(){
    SDL_Rect srcrect;
    //render
    srcrect = {STONE_GROUND_X_SELECTION,STONE_GROUND_Y_SELECTION,STONE_GROUND_SIZE,STONE_GROUND_SIZE};
    for(int r = 0; r < game_map->getArrayDimensions().y; r++){
        for(int c = 0; c < game_map->getArrayDimensions().x; c++){
            //if statement makes game render map only if it is in the window and game area
            //
            if(game_map->getBlock(c, r)->dstrect.x >= 0 &&
               game_map->getBlock(c, r)->dstrect.y >= 0 &&
               game_map->getBlock(c, r)->dstrect.x < WINDOW_WIDTH &&
               game_map->getBlock(c, r)->dstrect.y + game_map->getBlock(c, r)->dstrect.h <= WINDOW_HEIGHT - TOOLBAR_PANE_HEIGHT){
                
                //determine which texture to display for ground type
                int texType = 0;
                switch (game_map->getBlock(c, r)->getGroundType()) {
                    case STONE:
                        texType = 2;
                        break;
                        
                    default:
                        break;
                }
                
                //render ground of block
                SDL_RenderCopy(renderer, game_currentTextures[texType].texture, &srcrect, &game_map->getBlock(c, r)->dstrect);
                
                //TODO: Render stuff contained by block
                
                //render hero
                if(game_map->getBlock(c, r)->getContainedItem() == game_hero){
                    SDL_Rect hero_srcrect = {game_hero->getMoveCounter()*HERO_IMAGE_SPRITE_SIZE,game_hero->getOrientation()*HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE};
                    SDL_RenderCopy(renderer, game_currentTextures[1].texture, &hero_srcrect, &game_map->getBlock(c, r)->dstrect);
                }
                
                //render NPC GU TEST
                if(game_map->getBlock(c, r)->getContainedItem() == game_NPC){
                    SDL_Rect hero_srcrect = {game_NPC->getMoveCounter()*HERO_IMAGE_SPRITE_SIZE,game_NPC->getOrientation()*HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE};
                    SDL_RenderCopy(renderer, game_currentTextures[3].texture, &hero_srcrect, &game_map->getBlock(c, r)->dstrect);
                }
                
                
            }
        }
    }
}

void game::shiftMap(Orientation direction){
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
    for(int r = 0; r < game_map->getArrayDimensions().y; r++){
        for(int c = 0; c < game_map->getArrayDimensions().x; c++){
            game_map->getBlock(c, r)->dstrect.x += xShift;
            game_map->getBlock(c, r)->dstrect.y += yShift;
        }
    }
}

//moves the game hero on the map by one unit, can be later modified to move any GameObject
void game::moveHero(Orientation direction){
    game_hero->incrementMoveCounter();
    game_hero->setOrientation(direction);
    
    //determine coordinate of next block
    Coordinate nextBlock = game_hero->getLocationInMap();
    switch (direction) {
        case ORIENTATION_UP:
            nextBlock.y++;
            break;
        case ORIENTATION_DOWN:
            nextBlock.y--;
            break;
        case ORIENTATION_RIGHT:
            nextBlock.x++;
            break;
        case ORIENTATION_LEFT:
            nextBlock.x--;
            break;
        default:
            break;
    }
    
    //exit function if next block does not in map
    if(nextBlock.x < 0 ||
       nextBlock.x >= game_map->getArrayDimensions().x ||
       nextBlock.y < 0 ||
       nextBlock.y >= game_map->getArrayDimensions().y){
        return;
    }
    //exit function if next block can't be moved into
    if(!game_map->getBlock(nextBlock)->canMoveInto()){
        return;
    }
    
    //set current block to empty
    game_map->deOccupyBlock(game_hero->getLocationInMap());
    //move character to next block
    game_map->occupyBlock(nextBlock, game_hero);
    
}


//Initialize SDL
void game::initSDL(){
    // Initiliaze SDL video and our timer.
    if (  SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER)  < 0){
        cerr << "Error in Init(). Could not initialize SDL." << endl;
    }
    
    //create game window
    game_window =  SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
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
    
    //push main menu onto stack
    stateStruct state;
    state.stateMethod = mainMenuInit();
    game_stateStack.push(state);
    
    //set the game timer
    game_timer = SDL_GetTicks();
    
}
//Close SDL
void closeSDL(){
    //Deallocate surface
    SDL_FreeSurface( game_backBuffer );
    game_backBuffer = NULL;
    
    //Destroy window
    SDL_DestroyWindow( game_window );
    game_window = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();
}

//-----Helper Methods

//checks if given coordinates are inside a rectangle
bool checkIfInside(SDL_Rect dstrect, int x, int y){
    return (x >= dstrect.x &&
            x <= dstrect.x + dstrect.w &&
            y >= dstrect.y &&
            y <= dstrect.y + dstrect.h);
}
//empties state stack to lead to end of game
void endGame(){
    while(!game_stateStack.empty()){
        game_stateStack.pop();
    }
}
//empties the currentTextures vector
void emptyTextures(){
    for(int i = 0; i < game_currentTextures.size(); i++){
        SDL_DestroyTexture(game_currentTextures[i].texture);
    }
    game_currentTextures.clear();
}



void renderCombetScen(){
    SDL_Rect hero_srcrect = {HERO_IMAGE_SPRITE_SIZE,3*HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE};
    SDL_Rect hero_dstrect={0, static_cast<int>(h*0.45),200,200};
    SDL_RenderCopy(renderer, game_currentTextures[1].texture, &hero_srcrect, &hero_dstrect);
    
    SDL_Rect npc_srcrect = {HERO_IMAGE_SPRITE_SIZE,2*HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE,HERO_IMAGE_SPRITE_SIZE};
    SDL_Rect npc_dstrect={static_cast<int>(w*0.8), 0,200,200};
    SDL_RenderCopy(renderer, game_currentTextures[1].texture, &npc_srcrect, &npc_dstrect);
    
    //render the status
    
    White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
    surfaceMessage = TTF_RenderText_Solid(Sans, "Welcome", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    
    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
    
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect
    SDL_RenderCopy(renderer,Message,NULL,&Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
