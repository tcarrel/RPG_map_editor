
#include "stdafx.h"




/*static*/ const Interface_t Menu::type_ = INTERFACE_MENU;



Menu::Menu( Console* c ) :
    Interface( c, INTERFACE_MENU ),
    next_( type_ )
{}



void Menu::register_data_store( Play_Data* pd )
{
    game_data_ = pd;
    funds_ = new Money_Display( game_data_->money_addr() );
    funds_box_ = new Text_Box( funds_ );
}



Interface_t Menu::run( void )
{
    __update();
    __render();

    return exit( next_ );
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
                next_ = type_;
                break;
            case CTRL_B:
                next_ = type_;
                break;
            case CTRL_Y:
                next_ = type_;
                break;
            case CTRL_X:
                next_ = type_;
                break;
            case CTRL_L:
                next_ = type_;
                break;
            case CTRL_R:
                next_ = type_;
                break;
            case CTRL_UP:
                next_ = type_;
                break;
            case CTRL_DOWN:
                next_ = type_;
                break;
            case CTRL_LEFT:
                next_ = type_;
                break;
            case CTRL_RIGHT:
                next_ = type_;
                break;
            case CTRL_SELECT:
                next_ = type_;
                break;
            case CTRL_START:
                next_ = INTERFACE_PAUSE;
                break;
            default:
                break;
            }
        }
        ctrl_previous_[ u ] = ctrl_[ u ];
    }
}



Interface_t Menu::exit( Interface_t& rv )
{
    Interface_t ret = rv;
    rv = type_;
    return ret;
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