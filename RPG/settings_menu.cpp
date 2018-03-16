

#include "stdafx.h"




Settings_Menu::Settings_Menu( Event_Manager* e, Window* w, Console* c ) :
    Interface( e, c, w, INTERFACE_SETTINGS )
{}



void Settings_Menu::run( void )
{
    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {

    }
}



Interface_t Settings_Menu::type( void )
{
    return INTERFACE_SETTINGS;
}



void Settings_Menu::do_controls( unsigned u )
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
