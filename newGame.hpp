//
//  newGame.hpp
//  DnDrD
//
//  Created by oscar on 2016-11-20.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef newGame_hpp
#define newGame_hpp

#include <stdio.h>
#include "GameMap2.hpp"
#include "Hero.hpp"
#include "NPC.hpp"
#include "defines.h"
#include <SDL2_ttf/SDL_ttf.h>
#include <stack>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2/SDL_thread.h"
#include <stdio.h>
using namespace std;

enum GameType{
    game_play,
    main_menu,
    combat,
    map_editor
};

struct textureStruct{
    SDL_Texture* texture;
    SDL_Rect dstrect;
};

struct stateStruct{
    void (*stateMethod)();
    string resourceType;
};

class newGame{
public:
    SDL_Surface* game_backBuffer;
    SDL_Window* game_window;
    SDL_Renderer* renderer;
    SDL_Event game_event;
    GameType type;
    bool quit=false;
    std::vector<textureStruct> game_currentTextures;
    std::vector<textureStruct> game_rendererTextures;
    std::vector<GameMap2> maps;
    //method
    void initSDL();
    void mainMenuInit();
    void GameRenderer();
    void mainMenuRender();
    void mapEditorRender();
    void play();
    void GameInputHandler();
    void mainManuInputHandler();
    void gameInit();
    bool checkIfInside(SDL_Rect dstrect, int x, int y);
    //constructor
    newGame();
    //deconstructor
    void endGame();
};
#endif /* newGame_hpp */
