#pragma once

class Interface;
class Console;
class Window;
class Event_Manager;

class Pause;
class Game_Map;
class Game_Over;

enum Interface_t;



/**
*   The battle screen.
*/
class Combat : public Interface
{
public:
    Combat( Event_Manager*, Window*, Console* ); //Ctor.

    void run( void ); //Runs the battle loop.

    Interface_t type( void ); //Returns the type.

    void add_state_machine_nodes( Pause*, Game_Map*, Game_Over* );

    friend class Event_Manager;

private:

    void do_controls( unsigned );

    Interface_t next_;
    Pause* pause_screen_;
    Game_Map* map_screen_;
    Game_Over* game_over_screen_;
};
