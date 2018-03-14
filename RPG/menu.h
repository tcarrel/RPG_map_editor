#pragma once

#include<vector>

class Interface;
class Console;

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
    Menu( Console* );  // Ctor.

    void init( Play_Data* );  //Initializes the menuing system. 
    Interface_t run( void );  //Run's the menu's main-loop.

    Interface_t type( void );

private:
    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

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

    Interface_t next_;
};