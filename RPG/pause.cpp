
#include "stdafx.h"




/*static*/ Screen_Texture Pause::screen_image_;



Pause::Pause( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_PAUSE )
{
    screen_ = w->get_dimensions();
    renderer_ = w->get_renderer();
}



void Pause::init( Text* t )
{
    text_ = t;

    pause_.text = "PAUSED";

    pause_.x = ( SCREEN_X_PIXELS / 2 ) - ( 3 * TEXT_CHARACTER_WIDTH );
    pause_.y = ( SCREEN_Y_PIXELS / 2 ) - ( ( 1 * TEXT_CHARACTER_HEIGHT ) / 2 );
    pause_.hl = TEXT_HIGHLIGHT_TYPE_BRIGHT;

    console_->vb_variable_value( "Pause", "pause_.text", pause_.text );
    console_->vb_variable_value( "Pause", "pause_.x", pause_.x );
    console_->vb_variable_value( "Pause", "pause_.y", pause_.y );
}



/**
*   Runs the pause screen 'loop.'
*/
void Pause::run( void )
{
    screen_image_.render();

    SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 204 );
    SDL_RenderFillRect( renderer_, &screen_ );
    text_->render( &pause_ );

    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
        ;
}



inline Interface_t Pause::type( void )
{
    return INTERFACE_PAUSE;
}



/**
*   Responds to player inpuet.  (Just unpausing.)
*/
void Pause::do_controls( unsigned u )
{
    if( ctrl_previous_[ CTRL_START ] && !ctrl_current_[ CTRL_START ] )
    {
        //next_ = came_from_;
        exit_ = true;
    }
    else
    {
        //next_ = type_;
        exit_ = false;
    }
    ctrl_previous_[ u ] = ctrl_current_[ u ];
}
