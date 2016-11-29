//
//  defines.h
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-11.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef defines_h
#define defines_h

//window defines
#define WINDOW_HEIGHT NUMBER_BLOCKS_DISPLAYED_Y * BLOCK_SIZE + TOOLBAR_PANE_HEIGHT
#define WINDOW_WIDTH NUMBER_BLOCKS_DISPLAYED_X * BLOCK_SIZE
#define WINDOW_NAME "DnDrD"

//number of blocks displayed
#define NUMBER_BLOCKS_DISPLAYED_Y 15
#define NUMBER_BLOCKS_DISPLAYED_X 25

//size of each block
#define BLOCK_SIZE 50

//height of area reserved for toolbar
#define TOOLBAR_PANE_HEIGHT 2 * BLOCK_SIZE

//frame rate limits
#define FRAMES_PER_SECOND 10
#define FRAME_RATE 1000/FRAMES_PER_SECOND

//main menu buttons sizing and placement defines
#define MENU_BUTTON_SCALE 3/4
#define MENU_BUTTON_WIDTH 400 * MENU_BUTTON_SCALE //382
#define MENU_BUTTON_HEIGHT 150  * MENU_BUTTON_SCALE //157
#define MENU_BUTTON_Y_OFFSET 50
#define MENU_BUTTON_SPACING 40

#define ITEM_EDITOR_BUTTON_ROWS 6

//sprite maps defines
#define STONE_GROUND_X_SELECTION 0
#define STONE_GROUND_Y_SELECTION 0
#define STONE_GROUND_SIZE 128
#define HERO_IMAGE_SPRITE_SIZE 128


//font defines
#define FONT_SIZE 28
#define COLOUR_BLACK SDL_Color{0,0,0,255}
#define COLOUR_WHITE SDL_Color{255,255,255,255}

//file paths
#define PATH_TO_BACKGROUND "background.jpg"
#define PATH_TO_GLOWING_SQAURE "glowingsquare.png"
#define PATH_TO_GRASS "grass.png"
#define PATH_TO_GROUND "ground.jpg"
#define PATH_TO_WALL "wall.png"
#define PATH_TO_WATER "water.png"
#define PATH_TO_HERO "hero.png"
#define PATH_TO_FONT "Luminari.ttf"
#define PATH_TO_MAP_EDITOR_ADD_ITEM "addItemButton.png"
#define PATH_TO_MAP_EDITOR_ADD_CHARACTER "addCharacterButton.png"
#define PATH_TO_MAP_EDITOR_SET_START "startingBlockButton.png"
#define PATH_TO_MAP_EDITOR_SET_END "endingBlockButton.png"
#define PATH_TO_MAP_EDITOR_EXIT "me_exit.png"
#define PATH_TO_MAP_EDITOR_NEXT "me_next.png"
#define PATH_TO_MAIN_MENU_BUTTON_CHARACTER_EDITOR "menu_buttons/main_character_editor.png"
#define PATH_TO_MAIN_MENU_BUTTON_EXIT "menu_buttons/main_exit.png"
#define PATH_TO_MAIN_MENU_BUTTON_ITEM_EDITOR "menu_buttons/main_item_editor.png"
#define PATH_TO_MAIN_MENU_BUTTON_MAP_EDITOR "menu_buttons/main_mapeditor.png"
#define PATH_TO_MAIN_MENU_BUTTON_NEW_GAME "menu_buttons/main_newgame.png"
#define PATH_TO_BLANK_SCROLL "blank_scroll.png"
#define PATH_TO_ITEM_EDITOR_NAME "item_editor_buttons/change_name.png"
#define PATH_TO_ITEM_EDITOR_TYPE "item_editor_buttons/change_type.png"
#define PATH_TO_ITEM_EDITOR_STR "item_editor_buttons/change_str.png"
#define PATH_TO_ITEM_EDITOR_DEX "item_editor_buttons/change_dex.png"
#define PATH_TO_ITEM_EDITOR_CON "item_editor_buttons/change_con.png"
#define PATH_TO_ITEM_EDITOR_INT "item_editor_buttons/change_int.png"
#define PATH_TO_ITEM_EDITOR_WIS "item_editor_buttons/change_wis.png"
#define PATH_TO_ITEM_EDITOR_CHA "item_editor_buttons/change_cha.png"
#define PATH_TO_ITEM_EDITOR_ARMOUR "item_editor_buttons/change_armour.png"
#define PATH_TO_ITEM_EDITOR_DMG "item_editor_buttons/change_dmg.png"
#define PATH_TO_ITEM_EDITOR_ATK "item_editor_buttons/change_atk.png"
#define PATH_TO_ITEM_EDITOR_SAVE "item_editor_buttons/save_exit.png"

#endif /* defines_h */
