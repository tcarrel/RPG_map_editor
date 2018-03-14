

#include "stdafx.h"


/*static*/ Console* Start_SDL::console_ = NULL;
/*static*/ Uint32   Start_SDL::reference_count_ = 0;
/*static*/ bool     Start_SDL::error_ = false;



Start_SDL::Start_SDL( Uint32 flags )
{
    this->init( flags );
    ++reference_count_;
}





Start_SDL::Start_SDL( Uint32 flags, bool& err )
{
    err = this->init( flags );
    ++reference_count_;
}





bool Start_SDL::init( Uint32 flags )
{
    if( console_ == NULL )
    {
        console_ = new Console;
    }

    if( flags == SDL_INIT_EVERYTHING || !( SDL_WasInit( SDL_INIT_EVERYTHING ) & flags ) )
    {
        error_ = SDL_InitSubSystem( flags ) < 0;
    }

    return !error_;
}




bool Start_SDL::good( void )
{
    return !error_;
}




void Start_SDL::show_errors( void )
{
    assert( console_ != NULL );
    if( !error_ )
    {
        console_->no_error( "SDL2", "Init OK", "Successfully initialized." );
        return;
    }
    console_->error( "SDL2", "Failed to initialize.", SDL_GetError() );
    error_ = false;
}



Start_SDL::~Start_SDL( void )
{
    --reference_count_;

    if( reference_count_ <= 0 )
    {
        console_->vb_only_no_err( "SDL2", "Attempting to quit." );
        delete console_;
        SDL_Quit();
    }
}