#pragma once

#include "stdafx.h"
#include "constants.h"

class Console;

class Interface;

class Menu;
class Pause;
class Start_Screen;
class Combat;
class Game_Map;
class Game_Over;
class Item_Creation;
class Save_Load_Menu;



/**
*   Responds to user inputs and allows the current interface to react to it.
*
*   TODO: Get gamepad and joystick controls to work correctly.
*/
class Event_Manager
{
public:

    Event_Manager( Console* = new Console );

    void operator() ( Interface* );
    void process( Interface* );
    const bool& quit( void );
    void quit_game( void );

    bool register_interface( Interface*, unsigned );

    ~Event_Manager( void );

private:

    void load_mappings( void );
    void key_down( SDL_Scancode, Interface* );
    void key_up( SDL_Scancode, Interface* );
    void joy_down( int, Interface* );
    void joy_up( int, Interface* );
    void joy_axis( Uint8, Sint16, Interface* );

    void all_registered( void );

    Console* console_;

    Start_SDL ev_mgr_init_;

    SDL_Event e_;
    bool quit_;

    // Interfaces
    int current_ixs_;
    Interface* ixs_[ALL_INTERFACES];

    bool ctrl_current_[ ALL_CTRL ];
    bool ctrl_previous_[ ALL_CTRL ];

    int joy_to_ctrl[ ALL_JOYS ];
    int key_to_ctrl[ ALL_KEYS ];

    int* joy_axes_;

    SDL_Joystick* gamepad_;
};