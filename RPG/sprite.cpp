

#include "stdafx.h"



/*static*/ unsigned Sprite::count_ = 0;



Sprite::Sprite( int x, int y, int w, int h )
{
    clip_.x = x;
    clip_.y = y;
    clip_.h = h;
    clip_.w = w;

    id_ = count_++;
}



inline int& Sprite::x( void )
{
    return clip_.x;
}



inline int& Sprite::y( void )
{
    return clip_.y;
}



inline int& Sprite::w( void )
{
    return clip_.w;
}



inline int& Sprite::h( void )
{
    return clip_.h;
}



SDL_Rect* Sprite::clip( void )
{
    return &clip_;
}



void Sprite::set( int x, int y, int w, int h )
{
    clip_.x = x;
    clip_.y = y;
    clip_.h = h;
    clip_.w = w;
}

