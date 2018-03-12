#pragma once

#include<SDL.h>
#include "text_line.h"

class Text;


class Box_Contents
{
public:
    Box_Contents( void );
    Box_Contents( const unsigned& );
    Box_Contents( const char[] );
    Box_Contents( const string& );
    Box_Contents( const Uint8_t_String& );

    ~Box_Contents( void );

    Uint8_t_String& operator[]( const unsigned& );
    Uint8_t_String& operator[]( const int& );

    Box_Contents& add_text( const char[] );
    Box_Contents& add_text( const string& );
    Box_Contents& add_text( const Uint8_t_String& );

    SDL_Rect& size( void );
    Line_of_Text* get_text( void );
    unsigned lines( void );

    virtual void update( void* = NULL, const unsigned& = 0) = 0;

    static void init( Text* t ) { text_system_ = t; }

protected:
    void enlarge_by_one( void );

    SDL_Rect size_; // stores values in terms of text row and column numbers.
    Line_of_Text* text_;

    static Text* text_system_;

private:
    void update_width( void );
};
