#pragma once

#include "text_line.h"
class Interface;
class Console;
class Window;
class Event_Manager;

class Text;
class Screen_Texture;

enum Interface_enum_t;



/**
*   The pause screen.
*/
class Pause : public Interface
{
public:
    Pause( Event_Manager*, Window*, Console* );  //  Ctor.

    void run( void ); // Runs the pause screen loop.

    Interface_enum_t type( void ); // Returns the type.

    friend class Event_Manager;

private:

    void do_controls( unsigned );

    Line_of_Text pause_;
    SDL_Rect screen_;
    static Screen_Texture screen_image_;

    SDL_Renderer* renderer_;

    Interface_enum_t next_;
};