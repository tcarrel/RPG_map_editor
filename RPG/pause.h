#pragma once

#include "text_line.h"
class Interface;
class Console;
class Text;
class Screen_Texture;

enum Interface_t;


class Pause : public Interface
{
public:
    Pause( Console* );

    void init( Text*, Window* );
    Interface_t run( void );

    Interface_t which( void ) { return type_; }

private:

    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

    Text* text_;
    Line_of_Text pause_;
    SDL_Rect screen_;
    static Screen_Texture screen_image_;

    SDL_Renderer* renderer_;

    static const Interface_t type_;
    Interface_t next_;
};