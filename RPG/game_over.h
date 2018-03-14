#pragma once

class Interface;
class Console;

enum Interface_t;



/**
*   The Game Over screen.
*/
class Game_Over : public Interface
{
public:
    Game_Over( Console* ); //Ctor.

    Interface_t run( void ); //Runs the loop for the game over screen.

    Interface_t type( void ); //Returns the type.

private:

    /*virtual*/ void do_controls( void ); //Responds to player input.
    Interface_t exit( void ); //Exits the game over screen's loop.

    Interface_t next_; //Where to return to.
};