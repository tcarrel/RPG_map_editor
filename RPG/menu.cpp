
#include "stdafx.h"





Menu::Menu( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_MENU )
{}



void Menu::init( Play_Data* pd )
{
    SDL_Rect dims = { TEXT_COLUMNS - 11, TEXT_ROWS - 3, 11, 1 };

    game_data_ = pd;
    base_menu_.funds_box =
        new Text_Box( new Money_Display( game_data_->money_addr() ), dims );

    dims = { 0, 0, 12, 17 };
    base_menu_.main_selections = new Text_Box(
        new Selectable_List( 2 ), dims );
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
        " Load Game",
        MENU_RETURN_VALUE__OPEN_LOAD_GAME_MENU );
    base_menu_.main_selections->add_text(
        " Return",
        MENU_RETURN_VALUE__EXIT_MENU );
    base_menu_.main_selections->add_text(
        " Quit",
        MENU_RETURN_VALUE__QUIT_GAME_REQUEST );

    active_window_stack_.push( base_menu_.main_selections );
    active_window_stack_.top()->contents()->activate();
}



void Menu::run( void )
{
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
            react( active_window_stack_.top()->command( CTRL_A ) );
            goto_interface_ = type();
            exit_ = false;
            return;
        case CTRL_UP:
            active_window_stack_.top()->command( CTRL_UP );
            goto_interface_ = type();
            exit_ = false;
            return;
        case CTRL_DOWN:
            active_window_stack_.top()->command( CTRL_DOWN );
            goto_interface_ = type();
            exit_ = false;
            return;
        case CTRL_START:
            goto_interface_ = INTERFACE_PAUSE;
            exit_ = false;
            return;
        default:
            goto_interface_ = type();
            exit_ = false;
            return;
        }
    }
}



void Menu::react( int menu_selection )
{
    switch( menu_selection )
    {
    case MENU_RETURN_VALUE__QUIT_GAME_REQUEST:
        confirm_quit();
        break;
    case MENU_RETURN_VALUE__QUIT_GAME:
        em_->quit_game();
        return;
    case MENU_RETURN_VALUE__EXIT_CURRENT_WINDOW:
        delete active_window_stack_.top();
        active_window_stack_.top() = NULL;
        active_window_stack_.pop();
        active_window_stack_.top()->contents()->activate();
        break;
    default:
        return;
    }
    ctrl_previous_[ CTRL_A ] = ctrl_current_[ CTRL_A ];
    ctrl_current_[ CTRL_A ] = false;
}



void Menu::confirm_quit( void )
{

    active_window_stack_.top()->contents()->deactivate();

    Selectable_List* yes_no = new Selectable_List(2);
    yes_no->add_text(
        "   Are you sure you want to quit?",
        MENU_UNSELECTABLE_ITEM );
    yes_no->add_text(
        " All unsaved progress will be lost.",
        MENU_UNSELECTABLE_ITEM );
    yes_no->add_text(
        "   No",
        MENU_RETURN_VALUE__EXIT_CURRENT_WINDOW );
    yes_no->add_text(
        "   Yes",
        MENU_RETURN_VALUE__QUIT_GAME );
    yes_no->activate();

    SDL_Rect coords = { ( TEXT_COLUMNS - 37 ) / 2,( TEXT_ROWS - 9 ) / 2, 36, 8 };

    Text_Box* confirm_quit = new Text_Box( yes_no, coords );

    open_windows_.push_back( confirm_quit );
    active_window_stack_.push( confirm_quit );
    confirm_quit = NULL;
    yes_no = NULL;
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
