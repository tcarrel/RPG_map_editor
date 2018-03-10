#pragma once

#include<SDL.h>
#include "text_line.h"



class Box_Contents
{
public:
    Box_Contents( void );
    ~Box_Contents( void );

private:
    SDL_Rect size_;
};