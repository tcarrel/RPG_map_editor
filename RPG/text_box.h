#pragma once

#include "text.h"




class Text_Box : public Text
{
public:
    Text_Box( Box_Contents* );

    void render( void );
    void render( Line_of_Text* text );
    static void set_fill( uint8_t, uint8_t, uint8_t, uint8_t );

    Box_Contents* contents( void );

private:

    void render_fill( void );
    void render_border( void );
    void render_char(
        unsigned,
        SDL_Rect*,
        unsigned = TEXT_HIGHLIGHT_TYPE_NORMAL );

    unsigned w_;
    unsigned h_;
    SDL_Rect box_;

    Box_Contents* content_;
    unsigned line_rendering_;

    static uint8_t        fill_color_[4];
    static SDL_Renderer*  renderer_;
    static bool           initialized_;
};