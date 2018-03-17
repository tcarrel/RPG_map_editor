
#include "stdafx.h"





Menu::Menu( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_MENU )
{}



void Menu::init( Play_Data* pd )
{
    game_data_ = pd;
    base_menu_.funds_box =
        new Text_Box(
            new Money_Display( game_data_->money_addr() ) );

    base_menu_.main_selections = new Text_Box( new Selectable_List( 2 ) );
    base_menu_.main_selections->add_text(
        " Inventory",
        MENU_RETURN_VALUE__OPEN_ITEM_INVENTORY );
    base_menu_.main_selections->add_text(
        " Magic",
        MENU_RETURN_VALUE__OPEN_MAGIC_MENU );
    base_menu_.main_selections->add_text(
        " Equipment ",
        MENU_RETURN_VALUE__OPEN_EQUIP_MENU );
    base_menu_.main_selections->add_text(
        " Status",
        MENU_RETURN_VALUE__OPEN_STATUS );
    base_menu_.main_selections->add_text(
        " Settings",
        MENU_RETURN_VALUE__OPEN_SETTINGS_MENU );
    base_menu_.main_selections->add_text(
        " Exit",
        MENU_RETURN_VALUE__EXIT_MENU );
    base_menu_.main_selections->add_text(
        " Quit",
        MENU_RETURN_VALUE__QUIT_GAME );

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
inline Interface_enum_t Menu::type( void )
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
            printf( "Selection:\t%i\n", active_window_->command( CTRL_A ) );
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
        case CTRL_START:
            goto_interface_ = INTERFACE_PAUSE;
            exit_ = false;
            break;
        default:
            goto_interface_ = type();
            exit_ = false;
            break;
        }
    }
}



/**
*   Updates the internal status before rendering.
*/
void Menu::__update( void )
{
    base_menu_.funds_box->contents()->update();
    base_menu_.main_selections->contents()->update();
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
