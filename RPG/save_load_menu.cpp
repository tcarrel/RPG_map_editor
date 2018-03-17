

#include "stdafx.h"






Save_Load_Menu::Save_Load_Menu( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_SAVE_LOAD_MENU )
{}



void Save_Load_Menu::run( void )
{
    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {

    }
}



inline Interface_enum_t Save_Load_Menu::type( void )
{
    return INTERFACE_SAVE_LOAD_MENU;
}



void Save_Load_Menu::do_controls( unsigned u )
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
}
