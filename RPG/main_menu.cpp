

#include "stdafx.h"



Main_Menu::Main_Menu( Console* c ) :
    Interface( c, INTERFACE_START_MENU )
{}



Interface_enum Main_Menu::run( void )
{

    return type_;
}