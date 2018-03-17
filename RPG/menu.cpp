
#include "stdafx.h"







Menu::Menu( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_MENU )
{}



void Menu::init( Play_Data* pd )
{
    game_data_ = pd;
    funds_ = new Money_Display( game_data_->money_addr() );
    base_menu_.funds_box = new Text_Box( funds_ );

    base_menu_.main_selections = new Text_Box( new Selectable_List );
    ( (Selectable_List*)base_menu_.main_selections->contents() )->set_heading_count( 0 );
    base_menu_.main_selections->add_text( " Item" );
    base_menu_.main_selections->add_text( " Magic" );
    base_menu_.main_selections->add_text( " Equip" );
    base_menu_.main_selections->add_text( " Status" );
    base_menu_.main_selections->add_text( " Settings" );
    base_menu_.main_selections->add_text( " Exit" );
    base_menu_.main_selections->add_text( " Quit" );

    active_window_ = base_menu_.main_selections;
    active_window_->contents()->activate();
}



void Menu::run( void )
{
    Console::vb_variable_value( " Menu", "this", this );

    goto_interface_ = type();

    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {
        switch( goto_interface_ )
        {
        case INTERFACE_PAUSE:
            pause_screen_->run();
            goto_interface_ = type();
            break;
        default:
            ;
        }
        __update();
        __render();
    }
}



/**
*   Returns the type.
*/
inline Interface_t Menu::type( void )
{
    return INTERFACE_MENU;
}



void Menu::add_state_machine_nodes( Pause* p, Item_Creation* ic , Save_Load_Menu* slm )
{
    pause_screen_ = p;
    item_creation_screen_ = ic;
    save_load_screen_ = slm;
}



/**
*   Responds to player inputs.
*/
void Menu::do_controls( unsigned u )
{
    if( ctrl_previous_[ u ] && !ctrl_current_[ u ] )
    {
        switch( u )
        {
        case CTRL_A:
            active_window_->command( CTRL_A );
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_B:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_Y:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_X:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_L:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_R:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_UP:
            active_window_->command( CTRL_UP );
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_DOWN:
            active_window_->command( CTRL_DOWN );
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_LEFT:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_RIGHT:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_SELECT:
            goto_interface_ = type();
            exit_ = false;
            break;
        case CTRL_START:
            goto_interface_ = INTERFACE_PAUSE;
            exit_ = false;
            break;
        default:
            break;
        }
    }
}



/**
*   Updates the internal status before rendering.
*/
void Menu::__update( void )
{
    funds_->update();
}



/**
*   Actually performs rendering.
*/
void Menu::__render( void )
{
    window_->clear();

    //render base menu
    base_menu_.funds_box->render();
    base_menu_.main_selections->render();

    //render additional windows.
    for( unsigned u = 0; u < open_windows_.size(); u++ )
    {
        open_windows_[ u ]->render();
    }

    window_->update();
}
