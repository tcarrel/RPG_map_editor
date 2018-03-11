#pragma once

#include "uint8_t_string.h"

struct Line_of_Text
{
    int x;
    int y;
    Uint8_t_String text;

    Line_of_Text( void );
    Line_of_Text( const Uint8_t_String& );
    Line_of_Text( const Line_of_Text& );

    Line_of_Text& operator=( const Uint8_t_String& );
    Line_of_Text& operator=( const Line_of_Text& );
};
