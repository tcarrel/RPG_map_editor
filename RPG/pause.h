#pragma once

#include "text_line.h"
class Interface;
class Console;
class Window;
class Event_Manager;

class Text;
class Screen_Texture;

enum Interface_t;



/**
*   The pause screen.
*/
class Pause : public Interface
{
public:
    Pause( Event_Manager*, Window*, Console* );  //  Ctor.

    void init( Text* ); // Initialization.
    void run( void ); // Runs the pause screen 'loop.'

    Interface_t type( void ); // Returns the type.

    friend class Event_Manager;

private:

    void do_controls( unsigned );

    Text* text_;
    Line_of_Text pause_;
    SDL_Rect screen_;
    static Screen_Texture screen_image_;

    SDL_Renderer* renderer_;

    Interface_t next_;
};