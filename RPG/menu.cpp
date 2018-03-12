
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



void Menu::__update( void )
{
    do_controls();
    funds_->update();
}



void Menu::__render( void )
{
    funds_box_->render();
}