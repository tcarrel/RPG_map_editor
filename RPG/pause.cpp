
#include "stdafx.h"




Pause::Pause( Console* c ) :
    Interface( c, INTERFACE_PAUSE )
{}



void Pause::init( Text* t, Window* w )
{
    text_ = t;
    screen_ = w->get_dimensions();
    renderer_ = w->get_renderer();

    pause_.text = "PAUSED";
    pause_.x =
        ( screen_.w / 2 ) -
        ( ( pause_.text.size() * TEXT_CHARACTER_WIDTH ) / 2 );
    pause_.y = ( screen_.h / 2 ) - ( TEXT_CHARACTER_HEIGHT / 2 );
}



Interface_enum Pause::run( void )
{
    SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 0x7f );
    SDL_RenderFillRect( renderer_, &screen_ );
    text_->render( &pause_ );

    return type_;
}
