#pragma once

#include<SDL.h>
#include "text_passage.h"
#include "text_line.h"

class Text;
class Passage;



class Box_Contents
{
public:
    Box_Contents( void );
    Box_Contents( const char[] );
    Box_Contents( const string& );
    Box_Contents( const Uint8_t_String& );
    Box_Contents( const Passage& );

    ~Box_Contents( void );

    void set_fixed_width( void );
    void unset_fixed_width( void );

    Uint8_t_String& operator[]( const unsigned& );
    Uint8_t_String& operator[]( const int& );

    Box_Contents& add_text( const char[] );
    Box_Contents& add_text( const string& );
    Box_Contents& add_text( const Uint8_t_String& );

    void set_position( int, int );
    void set_width( int );

    SDL_Rect& size( void );
    Passage* get_text( void );
    unsigned lines( void );

    virtual void update( void* = NULL, const unsigned& = 0) = 0;

    virtual void command( Control_t ) = 0;

    static void init( Text* );

protected:

    SDL_Rect size_; // Stores values in terms of text row and column numbers.
    Passage text_;
    bool fixed_width_;

    static Text* text_system_;

private:
    void update_width( void );
};
