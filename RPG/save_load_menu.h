#pragma once


class Play_Data;
class Interface;

enum Interface_t;



/**
*   The save and load screens.  This may need to be split into seperate
*  interfaces for saving and loading.
*/
class Save_Load_Menu : public Interface
{
public:
    Save_Load_Menu( Console* ); //Ctor.

    Interface_t run( void ); //Save menu loop.

    Interface_t type( void ); //Returns the type.


private:

    /*virtual*/ void do_controls( void ); //Responds to user input.
    Interface_t exit( void ); //Exits the loop.

    Interface_t next_;
};