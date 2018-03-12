

#include "stdafx.h"



Game_Over::Game_Over( Console* c ) :
    Interface( c, INTERFACE_GAME_OVER )
{}



Interface_enum Game_Over::run( void )
{

    return type_;
}



void Game_Over::do_controls( void )
{}