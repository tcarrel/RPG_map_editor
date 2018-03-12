
#include "stdafx.h"




/*static*/ const Interface_t Pause::type_ = INTERFACE_PAUSE;



Pause::Pause( Console* c ) :
    Interface( c, INTERFACE_PAUSE )
{}



void Pause::init( Text* t, Window* w )
{
    text_ = t;
    screen_ = w->get_dimensions();
    renderer_ = w->get_renderer();

    pause_.text = "PAUSED";

    pause_.x = ( SCREEN_X_PIXELS / 2 ) - ( 3 * TEXT_CHARACTER_WIDTH );
    pause_.y = ( SCREEN_Y_PIXELS / 2 ) - ( ( 1 * TEXT_CHARACTER_HEIGHT ) / 2 );

    console_->vb_variable_value( "Pause", "pause_.text", pause_.text );
    console_->vb_variable_value( "Pause", "pause_.x", pause_.x );
    console_->vb_variable_value( "Pause", "pause_.y", pause_.y );
}



Interface_t Pause::run( void )
{
    SDL_SetRenderDrawColor( renderer_, 0, 0, 63, 0x7f );
    SDL_RenderFillRect( renderer_, &screen_ );
    text_->render( TEXT_HIGHLIGHT_TYPE_NORMAL, &pause_ );

    do_controls();

    return exit( next_ );
}



void Pause::do_controls( void )
{
    if( ctrl_previous_[ CTRL_START ] && !ctrl_[ CTRL_START ] )
    {
        next_ = came_from_;
    }
    else
    {
        next_ = type_;
    }
    for( unsigned u = 0; u < ALL_CTRL; u++ )
    {
        ctrl_previous_[ u ] = ctrl_[ u ];
    }
}



Interface_t Pause::exit( Interface_t& var )
{
    Interface_t return_value = var;
    var = type_;
    return return_value;
}
