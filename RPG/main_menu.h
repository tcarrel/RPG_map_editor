#pragma once

class Interface;
class Console;

enum Interface_t;



/**
*   The initial menu that first appears when the game is loaded, after a game
*  over, or when the player exits.
*/
class Main_Menu : public Interface
{
public:
    Main_Menu( Console* ); //Ctor

    Interface_t run( void ); //Runs the loop for this menu.

    Interface_t type( void ); //Returns the type.

private:

    /*virtual*/ void do_controls( void ); //Responds to user input.
    Interface_t exit( void ); //Exits the loop.

    Interface_t next_; //Where to return to.
};
