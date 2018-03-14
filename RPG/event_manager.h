#pragma once

#include "stdafx.h"
#include "constants.h"

class Console;
class Interface;
class Main_Menu;
class Game_Map;
class Combat;
class Menu;
class Pause;



/**
*   Responds to user inputs and allows the current interface to react to it.
*
*   TODO: Get gamepad and joystick controls to work correctly.
*/
class Event_Manager
{
public:

    Event_Manager( Console* = new Console );

    void operator() ( void );
    void process( void );
    const bool& quit( void );

    bool register_interface( Interface*, unsigned );

    ~Event_Manager( void );

private:

    void load_mappings( void );
    void key_down( SDL_Scancode );
    void key_up( SDL_Scancode );
    void joy_down( int );
    void joy_up( int );
    void joy_axis( Uint8, Sint16 );

    void all_registered( void );

    Console* console_;

    Start_SDL ev_mgr_init_;

    SDL_Event e_;
    bool quit_;

    // Interfaces
    int current_ixs_;
    Interface* ixs_[ALL_INTERFACES];

    bool ctrl_[ ALL_CTRL ];

    int joy_to_ctrl[ ALL_JOYS ];
    int key_to_ctrl[ ALL_KEYS ];

    int* joy_axes_;

    SDL_Joystick* gamepad_;
};