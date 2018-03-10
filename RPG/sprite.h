#pragma once

#include "stdafx.h"



class Sprite
{
public:
    Sprite( int, int, int, int );

    int& x( void ) { return clip_.x; }
    int& y( void ) { return clip_.y; }
    int& w( void ) { return clip_.w; }
    int& h( void ) { return clip_.h; }
    SDL_Rect* clip( void ) { return &clip_; }

    void set( int, int, int, int );

private:
    SDL_Rect clip_;

    unsigned id_;
    static unsigned count_;

};