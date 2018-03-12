

#include "stdafx.h"



/*static*/ SDL_Texture* Screen_Texture::texture_ = NULL;
/*static*/ SDL_Surface* Screen_Texture::surface_ = NULL;
/*static*/ SDL_Renderer* Screen_Texture::renderer_ = NULL;
/*static*/ bool Screen_Texture::ready_ = false;



Screen_Texture::Screen_Texture( void )
{
    if( !ready_ )
    {
        return;
    }
    SDL_RenderCopy( renderer_, texture_, NULL, NULL );

}



/*static*/ void Screen_Texture::update( void )
{
    if( ready_ )
    {
        texture_ = SDL_CreateTextureFromSurface( renderer_, surface_ );
    }
}



/*static*/ void Screen_Texture::init( Window * w )
{
    if( !ready_ )
    {
        ready_ = true;
        renderer_ = w->get_renderer();
        surface_ = w->get_surface();
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
