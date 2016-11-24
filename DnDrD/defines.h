//
//  defines.h
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-11.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef defines_h
#define defines_h

#define WINDOW_HEIGHT NUMBER_BLOCKS_DISPLAYED_Y * BLOCK_SIZE + TOOLBAR_PANE_HEIGHT
#define WINDOW_WIDTH NUMBER_BLOCKS_DISPLAYED_X * BLOCK_SIZE
#define WINDOW_NAME "DnDrD"

#define NUMBER_BLOCKS_DISPLAYED_Y 15
#define NUMBER_BLOCKS_DISPLAYED_X 25

#define TOOLBAR_PANE_HEIGHT 2 * BLOCK_SIZE

#define FRAMES_PER_SECOND 10
#define FRAME_RATE 1000/FRAMES_PER_SECOND

#define MENU_BUTTON_SCALE 3/4
#define MENU_BUTTON_WIDTH 382 * MENU_BUTTON_SCALE
#define MENU_BUTTON_HEIGHT 157  * MENU_BUTTON_SCALE
#define MENU_BUTTON_Y_OFFSET 50
#define MENU_BUTTON_SPACING 30


#define BLOCK_SIZE 50

#define STONE_GROUND_X_SELECTION 0
#define STONE_GROUND_Y_SELECTION 0
#define STONE_GROUND_SIZE 128

#define HERO_IMAGE_SPRITE_SIZE 128

#define FONT_SIZE 48
#define FONT_COLOUR SDL_Color{0,0,0,255}

//file paths
#define PATH_TO_BACKGROUND "background.jpg"
#define PATH_TO_GLOWING_SQAURE "glowingsquare.png"
#define PATH_TO_GRASS "grass.png"
#define PATH_TO_GROUND "ground.jpg"
#define PATH_TO_WALL "wall.png"
#define PATH_TO_WATER "water.png"
#define PATH_TO_HERO "hero.png"
#define PATH_TO_FONT "Luminari.ttf"
#define PATH_TO_MAP_EDITOR_EXIT "me_exit.png"
#define PATH_TO_MAP_EDITOR_NEXT "me_next.png"
#define PATH_TO_MAIN_MENU_BUTTON_CHARACTER_EDITOR "menu_buttons/main_character_editor.png"
#define PATH_TO_MAIN_MENU_BUTTON_EXIT "menu_buttons/main_exit.png"
#define PATH_TO_MAIN_MENU_BUTTON_ITEM_EDITOR "menu_buttons/main_item_editor.png"
#define PATH_TO_MAIN_MENU_BUTTON_MAP_EDITOR "menu_buttons/main_mapeditor.png"
#define PATH_TO_MAIN_MENU_BUTTON_NEW_GAME "menu_buttons/main_newgame.png"
#define PATH_TO_BLANK_SCROLL "blank_scroll.png"

#endif /* defines_h */
