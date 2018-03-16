

#include "stdafx.h"






Game_Over::Game_Over( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_GAME_OVER )
{}



void Game_Over::run( void )
{

    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {

    }
}



inline Interface_t Game_Over::type( void )
{
    return INTERFACE_MAP;
}



void Game_Over::do_controls( unsigned u )
{
    if( ctrl_previous_[ u ] && !ctrl_current_[ u ] )
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
    ctrl_previous_[ u ] = ctrl_current_[ u ];
}
