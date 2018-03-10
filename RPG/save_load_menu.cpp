

#include "stdafx.h"



Save_Load_Menu::Save_Load_Menu( Console* c ) :
    Interface( c, INTERFACE_SAVE_LOAD_MENU )
{}



Interface_enum Save_Load_Menu::run( void )
{
    return type_;
}