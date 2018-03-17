

#include "stdafx.h"






Combat::Combat( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_COMBAT )
{}



void Combat::run( void )
{
    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {

    }
}



inline Interface_enum_t Combat::type( void )
{
    return INTERFACE_COMBAT;
}



void Combat::add_state_machine_nodes( Pause* p, Game_Map* gm, Game_Over* go )
{
    pause_screen_ = p;
    map_screen_ = gm;
    game_over_screen_ = go;
}



/**
*   Responds to user input.
*/
void Combat::do_controls( unsigned u )
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
