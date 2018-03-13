
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
    base_menu_.funds_box = new Text_Box( funds_ );
}



Interface_t Menu::run( void )
{
    __update();
    __render();

    return exit();
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
                exit_ = false;
                break;
            case CTRL_B:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_Y:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_X:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_L:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_R:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_UP:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_DOWN:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_LEFT:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_RIGHT:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_SELECT:
                next_ = type_;
                exit_ = false;
                break;
            case CTRL_START:
                next_ = INTERFACE_PAUSE;
                exit_ = true;
                break;
            default:
                break;
            }
        }
        ctrl_previous_[ u ] = ctrl_[ u ];
    }
}



Interface_t Menu::exit( void )
{
    Interface_t ret = exit_ ? next_ : type_;
    next_ = type_;
    return ret;
}



void Menu::__update( void )
{
    do_controls();
    funds_->update();
}



void Menu::__render( void )
{
    //render base menu
    base_menu_.funds_box->render();

    //render additional windows.
    for( unsigned u = 0; u < open_windows_.size(); u++ )
    {
        open_windows_[ u ]->render();
    }
}