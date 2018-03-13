

#include "stdafx.h"



/*static*/ SDL_Texture* Screen_Texture::texture_ = NULL;
/*static*/ SDL_Surface* Screen_Texture::surface_ = NULL;
/*static*/ SDL_Renderer* Screen_Texture::renderer_ = NULL;
/*static*/ Uint32 Screen_Texture::format_ = 0;
/*static*/ bool Screen_Texture::ready_ = false;




Screen_Texture::Screen_Texture( void )
{}



void Screen_Texture::render( void )
{
    if( ready_ )
    {
        SDL_RenderCopy( renderer_, texture_, NULL, NULL );
    }
}


/*static*/ void Screen_Texture::update( void )
{
    if( ready_ )
    {
        SDL_RenderReadPixels(
            renderer_,
            NULL,
            format_,
            surface_->pixels,
            surface_->pitch );
        texture_ = SDL_CreateTextureFromSurface( renderer_, surface_ );
    }
}



/*static*/ void Screen_Texture::init( Window * w )
{
    if( !ready_ )
    {
        ready_ = true;
        renderer_ = w->get_renderer();
        SDL_Rect dims = w->get_dimensions();
        format_ = w->format();
        SDL_Surface* temp = SDL_CreateRGBSurface(
            0,
            dims.w,
            dims.h,
            32,
            0xff000000,
            0x00ff0000,
            0x0000ff00,
            0x000000ff );
        surface_ = SDL_ConvertSurfaceFormat( temp, format_, 0 );
        SDL_FreeSurface( temp );

        SDL_RenderReadPixels(
            renderer_,
            NULL,
            format_,
            surface_->pixels,
            surface_->pitch );
        texture_ = SDL_CreateTextureFromSurface( renderer_, surface_ );
        atexit( destroy );
    }
}



Screen_Texture::~Screen_Texture( void )
{}



void Screen_Texture::destroy( void )
{
    SDL_DestroyTexture( texture_ );
    renderer_ = NULL;
    surface_ = NULL;
}
