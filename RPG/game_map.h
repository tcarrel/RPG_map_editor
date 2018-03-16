#pragma once

class Interface;
class Console;
class Window;
class Event_Manager;

class Pause;
class Combat;
class Menu;
class Item_Creation;

enum Interface_t;



/**
*   Interface for wandering the game world.
*/
class Game_Map : public Interface
{
public:
    Game_Map( Event_Manager*, Window*, Console* ); //Ctor.

    void run( void ); //Runs the loop for this interface.

    Interface_t type( void ); //Returns the type.

    void add_state_machine_nodes( Pause*, Combat*, Menu*, Item_Creation* );

    friend class Event_Manager;

private:

    void do_controls( unsigned ); //Responds to player input.

    Interface_t next_;
    Pause* pause_screen_;
    Combat* battle_;
    Menu* menu_screen_;
    Item_Creation* item_creation_screen_;
};