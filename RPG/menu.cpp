
#include "stdafx.h"




Menu::Menu( Console* c ) :
    Interface( c, INTERFACE_MENU )
{}



void Menu::register_data_store( Play_Data* pd )
{
    game_data_ = pd;
    funds_ = new Money_Display( game_data_->money_addr() );
    funds_box_ = new Text_Box( funds_ );
}



Interface_enum Menu::run( void )
{
    __update();
    __render();

    return type_;
}


void Menu::do_controls( void )
{
    for( unsigned u = 0; u < ALL_CTRL; u++ )
    {
        if( ctrl_previous_[ u ] && !ctrl_[ u ] )
        {
            switch( u )
            {
            case CTRL_START:
                game_data_->add_money( 5076543 );
                break;
            default:
                break;
            }
        }
        ctrl_previous_[ u ] = ctrl_[ u ];
    }
}



void Menu::__update( void )
{
    do_controls();
    funds_->update();
}



void Menu::__render( void )
{
    funds_box_->render();
}