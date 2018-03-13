
#include "stdafx.h"




/*static*/ const Interface_t Pause::type_ = INTERFACE_PAUSE;
/*static*/ Screen_Texture Pause::screen_image_;



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
    pause_.hl = TEXT_HIGHLIGHT_TYPE_BRIGHT;

    console_->vb_variable_value( "Pause", "pause_.text", pause_.text );
    console_->vb_variable_value( "Pause", "pause_.x", pause_.x );
    console_->vb_variable_value( "Pause", "pause_.y", pause_.y );
}



Interface_t Pause::run( void )
{
    screen_image_.render();

    SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 204 );
    SDL_RenderFillRect( renderer_, &screen_ );
    text_->render( pause_.hl, &pause_ );

    do_controls();

    return exit();
}



void Pause::do_controls( void )
{
    if( ctrl_previous_[ CTRL_START ] && !ctrl_[ CTRL_START ] )
    {
        //next_ = came_from_;
        exit_ = true;
    }
    else
    {
        //next_ = type_;
        exit_ = false;
    }
    for( unsigned u = 0; u < ALL_CTRL; u++ )
    {
        ctrl_previous_[ u ] = ctrl_[ u ];
    }
}



Interface_t Pause::exit( void )
{
    if( exit_ )
    {
        return came_from_;
    }
    else
    {
        return INTERFACE_PAUSE;
    }
}
