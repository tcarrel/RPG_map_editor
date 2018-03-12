
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
    text_->render( TEXT_HIGHLIGHT_TYPE_NORMAL, &pause_ );

    return type_;
}



void Pause::do_controls( void )
{
    for( unsigned u = 0; u < ALL_CTRL; u++ )
    {
        if( ctrl_previous_[ u ] && !ctrl_[ u ] )
        {
            switch( u )
            {
            case CTRL_A:
                break;
            case CTRL_B:
                break;
            case CTRL_Y:
                break;
            case CTRL_X:
                break;
            case CTRL_L:
                break;
            case CTRL_R:
                break;
            case CTRL_UP:
                break;
            case CTRL_DOWN:
                break;
            case CTRL_LEFT:
                break;
            case CTRL_RIGHT:
                break;
            case CTRL_SELECT:
                break;
            case CTRL_START:
                break;
            default:
                break;
            }
        }
        ctrl_previous_[ u ] = ctrl_[ u ];
    }
}
