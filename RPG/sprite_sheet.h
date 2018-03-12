#pragma once


#include "stdafx.h"
class Console;


class Sprite_Sheet
{
public:
    Sprite_Sheet( void );
    Sprite_Sheet( const string&, transparent_color* color_key = NULL );
    ~Sprite_Sheet( void );

    bool load( const string&, transparent_color* color_key = NULL );
    void free( void );

    int get_width( void );
    int get_height( void );

    void render( int, int, SDL_Rect* clip = NULL );

    bool ready( void ) { return ready_; }

    static void set_renderer( SDL_Renderer* );
    SDL_Renderer* get_renderer( void ) { return renderer_; }

    static void set_offsets( int, int );
    static int  get_x_offset( void ) { return offset_x_; }
    static int  get_y_offset( void ) { return offset_y_; }

protected:
    SDL_Texture* sheet_;
    int width_;
    int height_;

    bool ready_;


    static Console* console_;
    static unsigned self_count_;
    static SDL_Renderer* renderer_;

    static int  offset_x_;
    static int  offset_y_;
};