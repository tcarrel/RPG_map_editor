#pragma once

#include<vector>
#include<stack>

class Interface;
class Console;
class Window;
class Event_Manager;

class Pause;
class Item_Creation;
class Load_Menu;

class Money_Display;
class Text_Box;

class Play_Data;

enum Interface_enum_t;

using std::vector;
using std::stack;



/**
*   The in-game menu system.
*/
class Menu : public Interface
{
public:
    Menu( Event_Manager*, Window*, Console* );  // Ctor.

    void init( Play_Data* );  //Initializes the menuing system. 
    void run( void );  //Run's the menu's main-loop.

    Interface_enum_t type( void );

    void add_state_machine_nodes( Pause*, Item_Creation*, Load_Menu* );

    friend class Event_Manager;

private:

    void do_controls( unsigned );
    void react( int );
    void confirm_quit( void );
    void reset( void );

    void __update( void );
    void __render( void );

    struct
    {
        Text_Box* main_selections;
        Text_Box* funds_box;
    } base_menu_;

    vector<Text_Box*> open_windows_;
    stack<Text_Box*> active_window_stack_;

    Play_Data* game_data_;
    Pause* pause_screen_;
    Item_Creation* item_creation_screen_;
    Load_Menu* save_load_screen_;

    Interface_enum_t goto_interface_;
};