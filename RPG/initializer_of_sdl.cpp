

#include "stdafx.h"


/*static*/ Console* Start_SDL::console_ = NULL;
/*static*/ Uint32   Start_SDL::count_of_these_ = 0;
/*static*/ bool     Start_SDL::error_ = false;



Start_SDL::Start_SDL( Uint32 flags )
{
    this->init( flags );
    ++count_of_these_;
}





Start_SDL::Start_SDL( Uint32 flags, bool& err )
{
    err = this->init( flags );
    ++count_of_these_;
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
    else
    {
        string a = "SDL2";
        string b = "Init Skipped.";
        if( flags == SDL_INIT_TIMER )
        { 
            console_->no_error(
                a, b,
                "Timer subsystem has already been initialized, skipping." );
            return !error_;
        }
        if( flags == SDL_INIT_AUDIO )
        {
            console_->no_error(
                a, b,
                "Audio subsystem has already been initialized, skipping." );
            return !error_;
        }
        if( flags == SDL_INIT_VIDEO )
        {
            console_->no_error(
                a, b,
                "Video subsystem has already been initialized, skipping." );
            return !error_;
        }
        if( flags == SDL_INIT_JOYSTICK )
        {
            console_->no_error(
                a, b,
                "Joystick subsystem has already been initialized, skipping." );
            return !error_;
        }
        if( flags == SDL_INIT_HAPTIC )
        {
            console_->no_error(
                a, b,
                "Haptic feedback subsystem has already been initialized, skipping." );
            return !error_;
        }
        if( flags == SDL_INIT_GAMECONTROLLER )
        {
            console_->no_error(
                a, b,
                "Gamepad subsystem has already been initialized, skipping." );
            return !error_;
        }
        if( flags == SDL_INIT_EVENTS )
        {
            console_->no_error(
                a, b,
                "Events subsystem has already been initialized, skipping." );
            return !error_;
        }
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
    --count_of_these_;
    console_->vb_variable_value( "Start_SDL", "count_of_these_", count_of_these_ );

    if( count_of_these_ <= 0 )
    {
        console_->vb_only_no_err( "SDL2", "Attempting to quit." );
        delete console_;
        SDL_Quit();
    }
}