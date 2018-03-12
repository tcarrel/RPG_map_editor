

#include "stdafx.h"
#include<cassert>


/**
*    With the exception of a few systems that need to be initialized first,
*   this ctor is responsible for initializing all of the other systems in the
*   game and making the necessary connections between them (getting and
*   setting) various pointers.
*/
Game::Game( Console* c, Window* w, Event_Manager* e ) :
    sdl_init_( SDL_INIT_TIMER ),
    console_( *c ),
    window_( *w ),
    events_( *e ),
    start_menu_( c ),
    combat_( c ),
    on_map_( c ),
    menu_( c ),
    creation_( c ),
    pause_( c ),
    over_( c ),
    save_load_( c )
{
    renderer_ = window_.get_renderer();

    Interface::set_renderer( renderer_ );
    Sprite_Sheet::set_renderer( renderer_ );

    interface_[ INTERFACE_START_MENU ] = &start_menu_;
    interface_[ INTERFACE_MAP ] = &on_map_;
    interface_[ INTERFACE_COMBAT ] = &combat_;
    interface_[ INTERFACE_MENU ] = &menu_;
    interface_[ INTERFACE_ITEM ] = &creation_;
    interface_[ INTERFACE_PAUSE ] = &pause_;
    interface_[ INTERFACE_GAME_OVER ] = &over_;
    interface_[ INTERFACE_SAVE_LOAD_MENU ] = &save_load_;

    events_.register_interface( &start_menu_, INTERFACE_START_MENU );
    events_.register_interface( &on_map_,     INTERFACE_MAP );
    events_.register_interface( &combat_,     INTERFACE_COMBAT );
    events_.register_interface( &menu_,       INTERFACE_MENU );
    events_.register_interface( &creation_,   INTERFACE_ITEM );
    events_.register_interface( &pause_,      INTERFACE_PAUSE );
    events_.register_interface( &over_,       INTERFACE_GAME_OVER );
    events_.register_interface( &save_load_,  INTERFACE_SAVE_LOAD_MENU );

    play_data_ = new Play_Data;
    menu_.register_data_store( play_data_ );

    text_system_ = new Text;

    pause_.init( text_system_, w );
    Box_Contents::init( text_system_ );

}



Play_Data* Game::get_play_data( void )
{
    return play_data_;
}



void Game::main_loop( void )
{
    window_.update();

    unsigned goto_if = INTERFACE_MENU;
    current_interface_ = INTERFACE_MENU;

    while( !events_.quit() )
    {
        window_.clear();

        goto_if = interface_[ current_interface_ ]->run();
        if( goto_if != current_interface_ )
        {

        }
        
        events_();

        window_.update();
    }
}



Game::~Game( void )
{

}