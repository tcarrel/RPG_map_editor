#pragma once

class Interface;
class Console;
class Window;
class Event_Manager;

enum Interface_enum_t;



/**
*   The item creation loop.
*/
class Item_Creation : public Interface
{
public:

    Item_Creation( Event_Manager*, Window*, Console* ); //Ctor.

    void run( void ); //Runs the item creation menu loop.

    Interface_enum_t type( void ); //Returns the type.

    void add_state_machine_nodes( Pause* );

    friend class Event_Manager;

private:

    void do_controls( unsigned ); //React to player input.

    Interface_enum_t next_;
    Pause* pause_screen_;
};
