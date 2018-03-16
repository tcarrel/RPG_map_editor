

#include "stdafx.h"




SDL_Rect image_scaler( SDL_Surface* image, int screen_x, int screen_y )
{
    SDL_Rect scale = { 0, 0, 0, 0 };

    float
        x = itof( screen_x ),
        y = itof( screen_y ),
        screen_ar = x / y,
        image_ar = itof( image->w ) / itof( image->h );

    if( screen_ar >= image_ar )
    {
        scale.h = screen_y;
        scale.w = ftoi( itof( scale.h )*image_ar );
        return scale;
    }

    scale.w = screen_x;
    scale.h = ftoi( itof( scale.w ) / image_ar );

    return scale;
}



SDL_Rect image_centered( SDL_Surface* image, int screenx, int screeny )
{
    SDL_Rect position = { 0, 0, 0, 0 };

    float
        screen_ar = itof( screenx ) / itof( screeny ),
        image_ar = itof( image->w ) / itof( image->h );

    if( screen_ar > image_ar )
    {        
        position.x = ( screenx - ftoi( itof( screeny ) * image_ar ) ) / 2;
        return position;
    }

    position.y = ( screeny - ftoi( itof( screenx ) / image_ar ) ) / 2;
    return position;
}



SDL_Rect image_fullscreen_uniform_scale__centered(
    SDL_Surface* image,
    int screen_width,
    int screen_height )
{
    SDL_Rect
        scale = image_scaler( image, screen_width, screen_height ),
        pos = image_centered( image, screen_width, screen_height );

    return{ pos.x, pos.y, scale.w, scale.h };
}



inline int ftoi( float f )
{
    return (int)f;
}



inline float itof( int i )
{
    return (float)i;
}
