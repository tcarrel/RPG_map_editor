
#include "stdafx.h"




Game_Map::Game_Map( Console* c ) :
    Interface( c, INTERFACE_MAP )
{}



Interface_enum Game_Map::run( void )
{

    return type_;
}