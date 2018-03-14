#pragma once

#include "stdafx.h"



/**
*   A wrapper for SDL_Rect to be used for rendering sprites that are part of a
*  sprite sheet.
*/
class Sprite
{
public:
    Sprite( int, int, int, int );

    int& x( void );
    int& y( void );
    int& w( void );
    int& h( void );
    SDL_Rect* clip( void );

    void set( int, int, int, int );

private:
    SDL_Rect clip_;

    unsigned id_;
    static unsigned count_;

};