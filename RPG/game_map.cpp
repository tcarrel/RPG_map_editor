

#include "stdafx.h"



/*static*/ const Interface_t Game_Map::type_ = INTERFACE_MAP;



Game_Map::Game_Map( Console* c ) :
    Interface( c, INTERFACE_MAP )
{}



Interface_t Game_Map::run( void )
{

    return type_;
}



void Game_Map::do_controls( void )
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



Interface_t Game_Map::exit( Interface_t& var )
{
    Interface_t return_value = var;
    var = type_;
    return return_value;
}
