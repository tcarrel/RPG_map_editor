#pragma once

class Interface;
class Console;

enum Interface_t;



/**
*   The item creation loop.
*/
class Item_Creation : public Interface
{
public:

    Item_Creation( Console* ); //Ctor.

    Interface_t run( void ); //Runs the item creation menu loop.

    Interface_t type( void ); //Returns the type.

private:

    /*virtual*/ void do_controls( void ); //React to player input.
    Interface_t exit( void ); //Exits the loop.

    Interface_t next_;
};
