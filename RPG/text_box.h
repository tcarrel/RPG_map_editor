#pragma once

#include "text.h"




class Text_Box : public Text
{
public:
    Text_Box( int, int, Line_of_Text*, int );

    void render( Line_of_Text* text = NULL );
    static void set_fill( uint8_t, uint8_t, uint8_t, uint8_t );
private:

    void render_fill( void );
    void render_border( void );

    int w_;
    int h_;
    SDL_Rect box_;

    Line_of_Text* words_;

    static uint8_t        fill_color_[4];
    static SDL_Renderer*  renderer_;
    static bool           initialized_;
};