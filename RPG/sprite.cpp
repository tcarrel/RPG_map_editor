

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



void Sprite::set( int x, int y, int w, int h )
{
    clip_.x = x;
    clip_.y = y;
    clip_.h = h;
    clip_.w = w;
}

