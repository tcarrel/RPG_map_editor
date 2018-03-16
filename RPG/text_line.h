#pragma once

#include "uint8_t_string.h"



/**
*   A struct with a copy ctor and assignment operators for storing single
*  lines of text.
*/
struct Line_of_Text
{
    int x;
    int y;
    Text_Highlighting_t hl;
    Uint8_t_String text;

    Line_of_Text( void );
    Line_of_Text( const Uint8_t_String& );
    Line_of_Text( const Line_of_Text& );
    Line_of_Text( const char[] );

    Line_of_Text(
        const int&,
        const int&,
        const Text_Highlighting_t&,
        const Uint8_t_String& );
    Line_of_Text(
        const int&,
        const int&,
        const Text_Highlighting_t&,
        const char[] );

    Line_of_Text& operator=( const Uint8_t_String& );
    Line_of_Text& operator=( const char[] );
    Line_of_Text& operator=( const Line_of_Text& );
};
