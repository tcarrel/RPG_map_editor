

#include "stdafx.h"



/*static*/ Console* Sprite_Sheet::console_ = NULL;
/*static*/ unsigned Sprite_Sheet::self_count_ = 0;
/*static*/ SDL_Renderer* Sprite_Sheet::renderer_ = NULL;
/*static*/ int Sprite_Sheet::offset_x_ = 0;
/*static*/ int Sprite_Sheet::offset_y_ = 0;


Sprite_Sheet::Sprite_Sheet( void ) :
    sheet_( NULL ),
    width_( 0 ),
    height_( 0 )
{
    if( self_count_ == 0 )
    {
        console_ = new Console;
    }
    self_count_++;
}




Sprite_Sheet::~Sprite_Sheet( void )
{
    this->free();
    --self_count_;
    if( self_count_ == 0 )
    {
        delete console_;
        console_ = NULL;
    }
}



bool Sprite_Sheet::load( const string& path, transparent_color* color_key )
{
    this->free();

    SDL_Texture* new_texture = NULL;

    SDL_Surface* loaded = SDL_LoadBMP( path.c_str() );
    if( !loaded )
    {
        string long_msg(
            "Unable to load sprite sheet <" +
            path +
            ">." +
            SDL_GetError() );

        console_->error( "SDL2", "Unable to load sprite sheet.", long_msg );
        return false;
    }

    if( color_key )
    {
        SDL_SetColorKey(
            loaded,
            SDL_TRUE,
            SDL_MapRGB(
                loaded->format,
                color_key->r,
                color_key->g,
                color_key->b ) );
    }

    new_texture = SDL_CreateTextureFromSurface( renderer_, loaded );
    Console::vb_variable_value( "Sprite_Sheet", "renderer_", renderer_ );
    if( !new_texture )
    {
        string shrt(
            "Unable to create texture from <" + path + ">."
        );
        string longm(
            "Unable to create texture from <" + path + ">: " + SDL_GetError()
        );
        console_->error( "SDL2", shrt, longm );
        return false;
    }

    width_  = loaded->w;
    height_ = loaded->h;

    SDL_FreeSurface( loaded );
    loaded = NULL;

    sheet_ = new_texture;
    new_texture = NULL;

    console_->vb_only_no_err( "Sprite_Sheet", "Sheet " + path + ", loaded." );
    console_->vb_variable_value( "Sprite_Sheet", "SDL_Texture*", sheet_ );

    return !sheet_;
}



void Sprite_Sheet::free( void )
{
    if( sheet_ )
    {
        SDL_DestroyTexture( sheet_ );
        sheet_ = NULL;
        width_ = height_ = 0;
    }
}



int Sprite_Sheet::get_height( void )
{
    return height_;
}



int Sprite_Sheet::get_width( void )
{
    return width_;
}



void Sprite_Sheet::set_renderer( SDL_Renderer* r )
{
    Console::vb_variable_value( "Sprite_Sheet", "set_renderer()", r );
    renderer_ = r;
}



void Sprite_Sheet::render( int x, int y, SDL_Rect* clip )
{
    SDL_Rect quad = { x + offset_x_, y + offset_y_, width_, height_ };

    if( clip )
    {
        quad.h = clip->h;
        quad.w = clip->w;
    }

    SDL_RenderCopy( renderer_, sheet_, clip, &quad );
}



/*static*/ void Sprite_Sheet::set_offsets( int w, int h )
{
    offset_x_ = w;
    offset_y_ = h;
}