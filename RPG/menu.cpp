
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
    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {

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
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_B:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_Y:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_X:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_L:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_R:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_UP:
            active_window_->command( CTRL_UP );
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_DOWN:
            active_window_->command( CTRL_DOWN );
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_LEFT:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_RIGHT:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_SELECT:
            came_from_ = type();
            exit_ = false;
            break;
        case CTRL_START:
            came_from_ = INTERFACE_PAUSE;
            exit_ = true;
            break;
        default:
            break;
        }
    }
    ctrl_previous_[ u ] = ctrl_current_[ u ];
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
    //render base menu
    base_menu_.funds_box->render();
    base_menu_.main_selections->render();

    //render additional windows.
    for( unsigned u = 0; u < open_windows_.size(); u++ )
    {
        open_windows_[ u ]->render();
    }

}
