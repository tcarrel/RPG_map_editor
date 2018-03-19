#pragma once

#include "text.h"
class Uint8_t_String;



/**
*   Abstracts text boxes and is responsible for drawing their borders and
*  fill.
*/
class Text_Box : public Text
{
public:
    Text_Box( Box_Contents*, const SDL_Rect& = { 0, 0, 0, 0 } );

    void render( void );
    void render( Line_of_Text* text );
    static void set_fill( uint8_t, uint8_t, uint8_t, uint8_t );

    void set_size( const int&, const int& );
    void set_pos( const int&, const int& );
    void set_width( const int& );
    void set_height( const int& );
    void set_x_coord( const int& );
    void set_y_coord( const int& );
    void set_dimensions( const int&, const int&, const int&, const int& );

    void add_text( const char[], int );
    void add_text( const string&, int );
    void add_text( const Uint8_t_String&, int );
    Box_Contents* contents( void );

    int command( Control_enum_t );

private:
    int calculate_in_pixels__x_pos( int );
    int calculate_in_pixels__y_pos( int );
    int calculate_in_pixels__width( int );
    int calculate_in_pixels__height( int );
    
    void render_fill( void );
    void render_border( void );
    void render_char(
        unsigned,
        SDL_Rect*,
        unsigned = TEXT_HIGHLIGHT_TYPE_NORMAL );

    SDL_Rect dimensions_;

    Box_Contents* content_; //Change to vector?
    Box_Contents_enum_t type_;
    unsigned line_rendering_;

    static uint8_t        fill_color_[4];
    static SDL_Renderer*  renderer_;
    static bool           initialized_;
};