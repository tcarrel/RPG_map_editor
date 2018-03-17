

#include "stdafx.h"






Item_Creation::Item_Creation( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_ITEM )
{}



void Item_Creation::run( void )
{

    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {

    }
}



inline Interface_enum_t Item_Creation::type( void )
{
    return INTERFACE_ITEM;
}



void Item_Creation::add_state_machine_nodes( Pause* p )
{
    pause_screen_ = p;
}



void Item_Creation::do_controls( unsigned u )
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
