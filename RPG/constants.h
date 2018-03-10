#pragma once

#include "stdafx.h"
#define SCREEN_X_PIXELS (1920)
#define SCREEN_Y_PIXELS (1080)

const char GAME_TITLE[] = "RPG";
const int  JOY_DEAD_ZONE = 9000;

#define ALL_KEYS (0x11d)


#define TEXT_CHARACTER_WIDTH (32)
#define TEXT_CHARACTER_HEIGHT (32)
#define TEXT_ROW_HEIGHT (32)
//#define TEXT_LEFT_MARGIN (10)
#define TEXT_CHARACTERS_PER_ROW (50)
#define TEXT_MAX_ROWS ( SCREEN_Y_PIXELS / TEXT_CHARACTER_HEIGHT )

#define TEXT_SPRITE_SHEET_FILE_NAME "text2.bmp"


#define MAX_MONEY (99999999)

enum Interface_enum
{
    INTERFACE_START_MENU,
    INTERFACE_MAP,
    INTERFACE_PAUSE,
    INTERFACE_COMBAT,
    INTERFACE_MENU,
    INTERFACE_ITEM,
    INTERFACE_GAME_OVER,
    INTERFACE_SAVE_LOAD_MENU,

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
enum Joy_enum
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



enum Control_enum
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
    CTRL_ALT,
    CTRL_F4,

    CTRL_NULL,

    ALL_CTRL
};



enum Special_Character
{
    CHAR_COIN = 128U,
    CHAR_HAND__LEFT = 129U,
    CHAR_HAND__RIGHT = 130U,
    CHAR_25_PERCENT = 131U,
    CHAR_50_PERCENT = 132U,
    CHAR_75_PERCENT = 133U,
    CHAR_CORNER_TOP = 134U,
    CHAR_CORNER_TOP_RIGHT = 135U,
    CHAR_CORNER_RIGHT = 136U,
    CHAR_CORNER_BOTTOM_RIGHT = 137U,
    CHAR_CORNER_BOTTOM = 138U,
    CHAR_CORNER_BOTTOM_LEFT = 139U,
    CHAR_CORNER_LEFT = 140U,
    CHAR_CORNER_TOP_LEFT = 141U,
    CHAR_INVERTED_EXCLAMATION_MARK = 173U
};



enum Text_Box_Border
{
    TB_TOP,
    TB_TOP_RIGHT,
    TB_RIGHT,
    TB_BOTTOM_RIGHT,
    TB_BOTTOM,
    TB_BOTTOM_LEFT,
    TB_LEFT,
    TB_TOP_LEFT,
    ALL_TEXT_BOX_BORDERS
};