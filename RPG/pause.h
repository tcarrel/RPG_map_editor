#pragma once

#include "text_line.h"
class Interface;
class Console;
class Text;
class Screen_Texture;

enum Interface_t;



/**
*   The pause screen.
*/
class Pause : public Interface
{
public:
    Pause( Console* );  //  Ctor.

    void init( Text*, Window* ); // Initialization.
    Interface_t run( void ); // Runs the pause screen 'loop.'

    Interface_t type( void ); // Returns the type.

private:

    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

    Text* text_;
    Line_of_Text pause_;
    SDL_Rect screen_;
    static Screen_Texture screen_image_;

    SDL_Renderer* renderer_;

    Interface_t next_;
};