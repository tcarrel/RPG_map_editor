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
    Text_Box( Box_Contents* );

    void render( void );
    void render( Line_of_Text* text );
    static void set_fill( uint8_t, uint8_t, uint8_t, uint8_t );

    void add_text(
        const char[],
        int = MENU_RETURN_VALUE__NO_VALUES_TO_BE_USED );
    void add_text(
        const string&,
        int = MENU_RETURN_VALUE__NO_VALUES_TO_BE_USED );
    void add_text(
        const Uint8_t_String&,
        int = MENU_RETURN_VALUE__NO_VALUES_TO_BE_USED );
    Box_Contents* contents( void );

    int command( Control_enum_t );

private:

    void update_size( void );

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
    Box_Contents_enum_t type_;
    unsigned line_rendering_;

    static uint8_t        fill_color_[4];
    static SDL_Renderer*  renderer_;
    static bool           initialized_;
};