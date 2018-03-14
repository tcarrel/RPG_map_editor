

#include "stdafx.h"



/*static*/ unsigned Sprite::count_ = 0;



/**
*   Sets all variables.
*/
Sprite::Sprite( int x, int y, int w, int h )
{
    set( x, y, w, h );
    id_ = count_++;
}


/**
*   Horizontal (x) position on the sprite sheet.
*/
inline int& Sprite::x( void )
{
    return clip_.x;
}



/**
*   Vertical (y) position on the sprite sheet.
*/
inline int& Sprite::y( void )
{
    return clip_.y;
}



/**
*   The width of the sprite.
*/
inline int& Sprite::w( void )
{
    return clip_.w;
}



/**
*   The height of the sprite.
*/
inline int& Sprite::h( void )
{
    return clip_.h;
}



/**
*  The SDL_Rect containing the sprite's size and position on the sprite sheet.
*/
SDL_Rect* Sprite::clip( void )
{
    return &clip_;
}



/**
*  Performs the same function as the basic constructor.
*/
void Sprite::set( int x, int y, int w, int h )
{
    clip_.x = x;
    clip_.y = y;
    clip_.h = h;
    clip_.w = w;
}

