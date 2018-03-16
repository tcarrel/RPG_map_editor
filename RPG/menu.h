#pragma once

#include<vector>

class Interface;
class Console;
class Window;
class Event_Manager;

class Pause;
class Item_Creation;
class Save_Load_Menu;

class Money_Display;
class Text_Box;

class Play_Data;

enum Interface_t;

using std::vector;



/**
*   The in-game menu system.
*/
class Menu : public Interface
{
public:
    Menu( Event_Manager*, Window*, Console* );  // Ctor.

    void init( Play_Data* );  //Initializes the menuing system. 
    void run( void );  //Run's the menu's main-loop.

    Interface_t type( void );

    void add_state_machine_nodes( Pause*, Item_Creation*, Save_Load_Menu* );

    friend class Event_Manager;

private:
    void do_controls( unsigned );

    void __update( void );
    void __render( void );

    Money_Display* funds_;
    struct
    {
        Text_Box* main_selections;
        Text_Box* funds_box;
    } base_menu_;

    vector<Text_Box*> open_windows_;
    Text_Box* active_window_;

    Play_Data* game_data_;
    Pause* pause_screen_;
    Item_Creation* item_creation_screen_;
    Save_Load_Menu* save_load_screen_;
};