#pragma once

#include "text_line.h"
class Interface;
class Console;
class Text;



class Pause : public Interface
{
public:
    Pause( Console* );

    void init( Text*, Window* );
    Interface_enum run( void );
private:

    /*virtual*/ void do_controls( void );

    Text* text_;
    Line_of_Text pause_;
    SDL_Rect screen_;

    SDL_Renderer* renderer_;
};