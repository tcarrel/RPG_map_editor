#pragma once

#include<SDL.h>
#include "text_line.h"

class Text;


class Box_Contents
{
public:
    Box_Contents( void );
    Box_Contents( const Uint8_t_String& );

    ~Box_Contents( void );

    Line_of_Text& operator[]( const unsigned& );
    Line_of_Text& operator[]( const int& );

    Box_Contents& operator+( const Uint8_t_String& );

    SDL_Rect& size( void );
    Line_of_Text* get_text( void );
    unsigned& lines( void );

    virtual void update( void* = NULL, const unsigned& = 0) = 0;

    static void init( Text* t ) { text_system_ = t; }

protected:
    SDL_Rect size_;
    Line_of_Text* text_;
    unsigned text_qty_;

    static Text* text_system_;
};
