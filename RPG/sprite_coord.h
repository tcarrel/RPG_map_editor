#pragma once

#include "sprite.h"
class Sprite;




struct Sprite_Coord
{
    int x;
    int y;
    Sprite* sprite;

    Sprite_Coord( int _x, int _y, Sprite* addr ) :
        x(_x), y(_y), sprite(addr)
    {}

    Sprite_Coord( const Sprite_Coord& copy_from )
    {
        *this = copy_from;
    }

    Sprite_Coord& operator=( const Sprite_Coord& rhs )
    {
        x = rhs.x;
        y = rhs.y;
        sprite = rhs.sprite;
        return *this;
    }

    ~Sprite_Coord( void )
    {
        //delete sprite;

        //  It's probably better to not free here but leave it as the
        // responsibility of whatever created it in the first place.
        sprite = NULL;
    }
};