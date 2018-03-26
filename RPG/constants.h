#pragma once

#include "stdafx.h"
#include<cmath>

/**
*   Define all global constants here.
*/




const char GAME_TITLE[] = "RPG";
const int  JOY_DEAD_ZONE = 9000;

// Basic screen settings. /////////////////////////////////////////////////////

#define SCREEN_X_PIXELS (1920)
#define SCREEN_Y_PIXELS (1080)
#define FRAMES_PER_SECOND (60)

#define DRAW_BORDERS (true)

// Controls. //////////////////////////////////////////////////////////////////

#define ALL_KEYS (0x11d)

#define KEY_IS_PRESSED (true)
#define KEY_IS_NOT_PRESSED (false)

#define GAME_CONTROLLER_MAPPING_DATABASE_FILE_PATH \
"Settings\\gamecontrollerdb.txt"
#define KEYBOARD_MAPPING_SETTINGS_FILE_PATH \
"Settings\\keyboard.mapping.bin"

#define TEXT_CHARACTER_WIDTH (32)
#define TEXT_CHARACTER_HEIGHT (32)
#define TEXT_ROW_HEIGHT (32)
#define TEXT_X_OFFSET ( TEXT_CHARACTER_WIDTH / 2 )
#define TEXT_Y_OFFSET ( TEXT_CHARACTER_HEIGHT / 2)

#define TEXT_COLUMNS (( SCREEN_X_PIXELS / TEXT_CHARACTER_WIDTH ) - 1)
#define TEXT_ROWS (( SCREEN_Y_PIXELS / TEXT_CHARACTER_HEIGHT ) - 1)

/**
*   Image paths.
*/
#define TEXT_NORMAL_SPRITE_SHEET_FILENAME "Graphics\\text_normal.bmp"
#define TEXT_GRAYED_SPRITE_SHEET_FILENAME "Graphics\\text_grayed.bmp"
#define TEXT_HIGHLIGHT_SPRITE_SHEET_FILENAME "Graphics\\text_highlight.bmp"
#define START_SCREEN_BACKGROUND_IMAGE_FILENAME \
        "Graphics\\start_screen_image.bmp"

// Gameplay info. /////////////////////////////////////////////////////////////

#define MAX_MONEY (99999999)

// Graphics. //////////////////////////////////////////////////////////////////

#define TILE_WIDTH (32)
#define TILE_HEIGHT (32)

#define CHARACTER_SPRITE_WIDTH (TILE_WIDTH)
#define CHARACTER_SPRITE_HEIGHT (TILE_HEIGHT) // + (TILE_HEIGHT/2)

const int SCREEN_X_TILES =
( (int)ceil( ( (double)SCREEN_X_PIXELS ) / ( (double)TILE_WIDTH ) ) );
const int SCREEN_Y_TILES =
( (int)ceil( ( (double)SCREEN_Y_PIXELS ) / ( (double)TILE_HEIGHT ) ) );

#define MAX_CHARACTER_NAME_LENGTH (11)

// Character sprite sheet file paths. /////////////////////////////////////////

#define SPRITE_SHEET__HENRIETTA__MASK_OFF "Graphics\\henrietta.bmp"

// Enumerations. //////////////////////////////////////////////////////////////

enum Interface_enum_t
{
    INTERFACE_START_MENU,
    INTERFACE_MAP,
    INTERFACE_PAUSE,
    INTERFACE_COMBAT,
    INTERFACE_MENU,
    INTERFACE_ITEM,
    INTERFACE_GAME_OVER,
    INTERFACE_LOAD_MENU,
    INTERFACE_SAVE_MENU,
    INTERFACE_SETTINGS,
    INTERFACE_NEW_GAME_SETUP,
    INTERFACE_CONFIRM_QUIT,
    INTERFACE_CHARACTER_NAMING,

    ALL_INTERFACES,

    _INTERFACE_BASE
};



// Based on the SuperNES.
//
//     L                                      R
// 
//          UP                             X
//     LEFT    RIGHT    SELECT  START    Y   A
//         DOWN                            B
//
enum Joy_enum_t
{
    JOY_X_BUTTON,       // 0
    JOY_A_BUTTON,
    JOY_B_BUTTON,
    JOY_Y_BUTTON,
    JOY_L_BUTTON,       // 4
    JOY_ZZ_UNUSED_01,
    JOY_R_BUTTON,
    JOY_ZZ_UNUSED_02,
    JOY_SELECT,         // 8
    JOY_START,          
    JOY_ZZ_UNUSED_03,
    JOY_ZZ_UNUSED_04,
    JOY_UP,             // 12
    JOY_DOWN,
    JOY_LEFT,
    JOY_RIGHT,
    ALL_JOYS           
};



enum Control_enum_t
{
    CTRL_X,
    CTRL_A,
    CTRL_B,
    CTRL_Y,
    CTRL_L,
    CTRL_R,
    CTRL_UP,
    CTRL_DOWN,
    CTRL_LEFT,
    CTRL_RIGHT,
    CTRL_START,
    CTRL_SELECT,
    CTRL_PAUSE,
    CTRL_ALT,
    CTRL_F4,

    CTRL_NULL,

    ALL_CTRL
};



enum Special_Character_enum_t
{
    CHAR_COIN = 128U,
    CHAR_HAND__LEFT = 129U,
    CHAR_HAND__RIGHT = 130U,
    CHAR_25_PERCENT = 131U,
    CHAR_50_PERCENT = 132U,
    CHAR_75_PERCENT = 133U,
    CHAR_BOX_TOP = 134U,
    CHAR_BOX_TOP_RIGHT = 135U,
    CHAR_BOX_RIGHT = 136U,
    CHAR_BOX_BOTTOM_RIGHT = 137U,
    CHAR_BOX_BOTTOM = 138U,
    CHAR_BOX_BOTTOM_LEFT = 139U,
    CHAR_BOX_LEFT = 140U,
    CHAR_BOX_TOP_LEFT = 141U,
    CHAR_ARROW_UP = 142U,
    CHAR_ARROW_DOWN = 143U,
    CHAR_ARROW_LEFT = 144U,
    CHAR_ARROW_RIGHT = 145U,
    CHAR_BOX_CENTERED_HORIZONTAL = 146U,
    CHAR_BOX_CENTERED_VERTICAL = 147U,
    CHAR_BOX_T_BOTTOM = 148U,
    CHAR_BOX_T_TOP = 149U,
    CHAR_BOX_T_LEFT = 150U,
    CHAR_BOX_T_RIGHT = 151U,
    CHAR_BOX_CENTERED_INTERSECTION = 152U,
    CHAR_INVERTED_QUESTION_MARK = 168U,
    CHAR_INVERTED_EXCLAMATION_MARK = 173U
};



enum Text_Highlighting_enum_t
{
    TEXT_HIGHLIGHT_TYPE_NORMAL,
    TEXT_HIGHLIGHT_TYPE_GRAYED,
    TEXT_HIGHLIGHT_TYPE_GREYED = TEXT_HIGHLIGHT_TYPE_GRAYED,
    TEXT_HIGHLIGHT_TYPE_BRIGHT,

    ALL_TEXT_HIGHLIGHT_TYPES
};



enum Box_Contents_enum_t
{
    BOX_GENERIC_TEXT,
    BOX_MONEY_DISPLAY,
    BOX_TEXT_SELECTABLE_LIST,

    BOX_BOX_CONTENTS_BASE_TYPE
};



enum Menu_Return_Values_enum_t
{
    MENU_UNSELECTABLE_ITEM = 0x80000000,

    MENU_RETURN_VALUE__NO_VALUES_TO_BE_USED,
    MENU_RETURN_VALUE__NO_RETURN,

    MENU_RETURN_VALUE__NO = 0,
    MENU_RETURN_VALUE__YES,

    MENU_RETURN_VALUE__OPEN_ITEM_INVENTORY,
    MENU_RETURN_VALUE__OPEN_MAGIC_MENU,
    MENU_RETURN_VALUE__OPEN_EQUIP_MENU,
    MENU_RETURN_VALUE__OPEN_STATUS,
    MENU_RETURN_VALUE__OPEN_SETTINGS_MENU,
    MENU_RETURN_VALUE__OPEN_LOAD_GAME_MENU,

    MENU_RETURN_VALUE__EXIT_MENU,
    MENU_RETURN_VALUE__EXIT_CURRENT_WINDOW,

    MENU_RETURN_VALUE__QUIT_GAME_REQUEST,
    MENU_RETURN_VALUE__QUIT_GAME
};



enum Cardinal_Directions_enum_t
{
    INVALID_DIRECTION = -1,

    DOWN,
    DOWN_LEFT,
    LEFT,
    DOWN_RIGHT,
    RIGHT,
    UP_RIGHT,
    UP,
    UP_LEFT,

    ALL_DIRECTIONS
};



enum Character_ID_t
{
    CHARACTER_MAIN,
    CHARACTER_HENRIETTA = CHARACTER_MAIN
};



enum Item_Type_t
{
    ITEM_KEY_ITEM,
    ITEM_CONSUMABLE = 0x01,
    ITEM_EQUIPABLE  = 0x01 << 1,
    ITEM_WEAPON     = 0x01 << 2,
    ITEM_ARMOR      = 0x01 << 3,
    ITEM_SWORD      = 0x01 << 4,
    ITEM_HAMMER     = 0x01 << 5
};



enum Item_ID_t
{

};
