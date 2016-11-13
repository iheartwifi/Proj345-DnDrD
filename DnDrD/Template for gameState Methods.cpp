////These are the three methods required for all game states.
////If you want to add your own game state to the game code, copy this template.
////Make sure to:
////Use a search and replace to replace gameState with the name of your new game state
////Not change code except in the areas designated.
////If you need to change code elsewhere in these methods then please contact me (Nelson) so that I can ensure all methods are consistent
////Not hardcode numbers. Please add entries to the defines.h file instead.
////Keep your code readable with comments and whitespace.
//
////-----Methods for gameState
//
////load resources for main menu
//void gameStateInit(){
//    //delete all textures already in game_currentTextures
//    for(int i = 0; i < game_currentTextures.size(); i++){
//        SDL_DestroyTexture(game_currentTextures[i].texture);
//    }
//    game_currentTextures.clear();
//    
//    //add textures to currentTextures one at a time
//    {
//        SDL_Surface*  addSurface = NULL;
//        SDL_Texture* addTexture = NULL;
//        SDL_Rect dstrect;
//        
//        //load background image
//        addSurface = IMG_Load("background.jpg");
//        dstrect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
//        addTexture = SDL_CreateTextureFromSurface(renderer, addSurface);
//        game_currentTextures.push_back(textureStruct{addTexture,dstrect});
//        
//        //-----Load Additional Resources Here
//        //
//        //
//        //
//        //
//        //-----End of Load Additional Resources
//    }
//    
//    //remove init method from state stack
//    game_stateStack.pop();
//    
//    //push the actual method onto the stack
//    stateStruct state;
//    state.stateMethod = gameState;
//    game_stateStack.push(state);
//    
//}
////handle input for main menu
//void gameStateInputHandler(){
//    //check for event
//    while ( SDL_PollEvent(&game_event) )
//    {
//        //quit game when window exit button is pressed
//        if (game_event.type == SDL_QUIT)
//        {
//            endGame();
//        }
//        //handle key presses here
//        if(game_event.type == SDL_KEYDOWN){
//            switch (game_event.key.keysym.sym) {
//                case SDLK_ESCAPE:
//                    //pop self off stack
//                    game_stateStack.pop();
//                    
//                    //clear textures vector
//                    emptyTextures();
//                    break;
//                //------Handle Other Key Presses Here
//                //
//                //
//                //
//                //
//                //------End of Handle Other Key Presses
//                default:
//                    break;
//            }
//        }
//
//        
//        //-----Handle Other Events Here
//        //
//        //
//        //
//        //
//        //-----End of Handle Other Events
//    }
//    return;
//}
////render the gameState
//void gameState(){
//    //if game_currentTextures is not initialized
//    if(game_currentTextures.empty()){
//        //remove current method from state stack
//        game_stateStack.pop();
//        
//        //add initialization method to state stack
//        stateStruct state;
//        state.stateMethod = gameStateInit;
//        game_stateStack.push(state);
//        
//        //break to initialize. Will return
//        return;
//    }
//    //limit frame rate to FRAME_RATE
//    if ( (SDL_GetTicks() - game_timer) >= FRAME_RATE )
//    {
//        gameStateInputHandler();
//        //ALL RENDERING CODE TAKES PLACE IN HERE
//        {
//            //Render background
//            SDL_Rect srcrect = {0,0,1773,1182};
//            SDL_RenderCopy(renderer, game_currentTextures[0].texture, &srcrect, &game_currentTextures[0].dstrect);
//            
//            //-----Render Other Textures Here
//            //
//            //
//            //
//            //
//            //-----End of Render Other Textures
//        }
//        //DO NOT PUT MORE CODE PAST HERE
//        
//        SDL_RenderPresent(renderer);
//        SDL_RenderClear(renderer);
//        
//        //part of framerate limiter
//        game_timer = SDL_GetTicks();
//    }
//    else{
//        //Wait remaining time
//        SDL_Delay( FRAME_RATE - (SDL_GetTicks() - game_timer) + 1 );
//    }
//}
