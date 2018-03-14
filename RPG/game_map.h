#pragma once

class Interface;
class Console;

enum Interface_t;



/**
*   Interface for wandering the game world.
*/
class Game_Map : public Interface
{
public:
    Game_Map( Console* ); //Ctor.

    Interface_t run( void ); //Runs the loop for this interface.

    Interface_t type( void ); //Returns the type.

private:

    /*virtual*/ void do_controls( void ); //Responds to player input.
    Interface_t exit( void ); //Exits the loop.

    Interface_t next_;
};