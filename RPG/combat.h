#pragma once

class Interface;
class Console;

enum Interface_t;



/**
*   The battle screen.
*/
class Combat : public Interface
{
public:
    Combat( Console* ); //Ctor.

    Interface_t run( void ); //Runs the battle loop.

    Interface_t type( void ); //Returns the type.

private:

    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

    Interface_t next_;
};
