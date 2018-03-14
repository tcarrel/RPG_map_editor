

#include "stdafx.h"


/*static*/ Console* Start_SDL::console_ = NULL;
/*static*/ bool     Start_SDL::exit_set_ = 0;
/*static*/ bool     Start_SDL::error_ = false;



/**
*   Starts an SDL Interface.
*/
Start_SDL::Start_SDL( Uint32 flags )
{
    this->init( flags );
}




/**
*   Starts an SDL Interfaces and returns the results of error checking.
*/
Start_SDL::Start_SDL( Uint32 flags, bool& err )
{
    err = this->init( flags );
}



/**
*   Actually performs the initialization of SDL subsystems.
*/
bool Start_SDL::init( Uint32 flags )
{
    if( !exit_set_ )
    {
        exit_set_ = true;
        atexit( SDL_Quit );
    }

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



/**
*   Were there errors during SDL's initializations.
*/
bool Start_SDL::good( void )
{
    return !error_;
}



/**
*   Display errors in the console.
*/
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