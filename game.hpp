//
//  game.hpp
//  DnDrD
//
//  Created by oscar on 2016-11-17.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

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
using namespace std;

enum GameType{
    game_play,
    main_menu,
    combat,
};

struct textureStruct{
    SDL_Texture* texture;
    SDL_Rect dstrect;
};

struct stateStruct{
    void (*stateMethod)();
    string resourceType;
};


//---Global game data

class game{
public:
    SDL_Surface* game_backBuffer = NULL;
    SDL_Window* game_window;
    SDL_Renderer* renderer = NULL;
    SDL_Event game_event; //receives user input
    
    int game_timer; //controls framerate
    std::vector<textureStruct> game_currentTextures;
    GameMap2* game_map;
    Hero* game_hero;
    stack<stateStruct> game_stateStack;
    //test GU
    NPC* game_NPC;
    GameType type;
    TTF_Font* Sans;//load font
    SDL_Color White;
    int w,h;
    SDL_Surface* surfaceMessage;
    SDL_Texture* Message;
    int timecounter=0;
    
    game();
    void closeSDL();
    void initSDL();
    void playgame();
    
private:
    void gameInputHandler();
    void gameInit();
    void mainMenuInit();
    void mainMenuInputHandler();
    void mainMenu();
    void shiftMap(Orientation direction);
    void renderMap();
    void moveHero(Orientation direction);
    void emptyTextures();
    void endGame();
    bool checkIfInside(SDL_Rect dstrect, int x, int y);
};
#endif /* game_hpp */
