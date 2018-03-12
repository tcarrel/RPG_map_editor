
#include "stdafx.h"




Menu::Menu( Console* c ) :
    Interface( c, INTERFACE_MENU )
{}



void Menu::register_money( unsigned* money_ptr )
{
    funds_ = new Money_Display( money_ptr );
    funds_box_ = new Text_Box( funds_ );
}



Interface_enum Menu::run( void )
{
    __update();
    __render();

    return type_;
}



void Menu::__update( void )
{
    funds_->update();
}



void Menu::__render( void )
{
    funds_box_->render();
}