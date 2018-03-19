#pragma once

#include "stdafx.h"
class Sprite_Sheet;



/**
*   A wrapper for SDL_Rect to be used for rendering sprites that are part of a
*  sprite sheet.
*/
class Sprite
{
public:
    Sprite( int, int, int, int, Sprite_Sheet* = NULL );

    int& x( void );
    int& y( void );
    int& w( void );
    int& h( void );
    SDL_Rect* clip( void );

    void set( int, int, int, int, Sprite_Sheet* sheet );

    void render( int, int );

    friend class Sprite_Sheet;

protected:
    static void set_renderer( SDL_Renderer* );

    SDL_Rect     clip_;
    SDL_Texture* sprite_sheet_;

    int offset_x_;
    int offset_y_;

    unsigned id_;
    static unsigned count_;
    
    static SDL_Renderer* renderer_;
};