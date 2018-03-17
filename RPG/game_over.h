#pragma once

class Interface;
class Console;
class Window;
class Event_Manager;

enum Interface_enum_t;



/**
*   The Game Over screen.
*/
class Game_Over : public Interface
{
public:
    Game_Over( Event_Manager*, Window*, Console* ); //Ctor.

    void run( void ); //Runs the loop for the game over screen.

    Interface_enum_t type( void ); //Returns the type.

    friend class Event_Manager;

private:

    void do_controls( unsigned ); //Responds to player input.

    Interface_enum_t next_; //Where to return to.
};