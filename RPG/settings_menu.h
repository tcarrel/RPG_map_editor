#pragma once

class Interface;
class Console;
class Window;
class Event_Manager;

enum Interface_t;



class Settings_Menu : public Interface
{
public:
    Settings_Menu( Event_Manager*, Window*, Console* ); //Ctor.

    void run( void ); //Save menu loop.

    Interface_t type( void ); //Returns the type.

    friend class Event_Manager;

private:

    void do_controls( unsigned ); //Responds to user input.

    Interface_t next_;

};