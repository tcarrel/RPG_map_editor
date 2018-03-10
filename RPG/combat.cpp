

#include "stdafx.h"



Combat::Combat( Console* c ) :
    Interface( c, INTERFACE_COMBAT )
{}



Interface_enum Combat::run( void )
{

    return type_;
}