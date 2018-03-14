

#include "stdafx.h"






Combat::Combat( Console* c ) :
    Interface( c, INTERFACE_COMBAT )
{}



Interface_t Combat::run( void )
{
    // Not implemented
    return type();
}



inline Interface_t Combat::type( void )
{
    return INTERFACE_COMBAT;
}



/**
*   Responds to user input.
*/
void Combat::do_controls( void )
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



/**
*  Exits combat, either to the map or to the game over screen.
*/
Interface_t Combat::exit( void )
{
    Interface_t ret = exit_ ? next_ : type();
    next_ = type();
    return ret;
}
