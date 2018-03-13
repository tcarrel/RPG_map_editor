

#include "stdafx.h"



/*static*/ const Interface_t Save_Load_Menu::type_ =
INTERFACE_SAVE_LOAD_MENU;



Save_Load_Menu::Save_Load_Menu( Console* c ) :
    Interface( c, INTERFACE_SAVE_LOAD_MENU )
{}



Interface_t Save_Load_Menu::run( void )
{
    return type_;
}



inline Interface_t Save_Load_Menu::which( void )
{
    return type_;
}



void Save_Load_Menu::do_controls( void )
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



Interface_t Save_Load_Menu::exit( void )
{
    Interface_t ret = exit_ ? next_ : type_;
    next_ = type_;
    return ret;
}
