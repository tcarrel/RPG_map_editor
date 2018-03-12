

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

    events_.register_interface( &start_menu_, INTERFACE_START_MENU );
    events_.register_interface( &on_map_,     INTERFACE_MAP );
    events_.register_interface( &combat_,     INTERFACE_COMBAT );
    events_.register_interface( &menu_,       INTERFACE_MENU );
    events_.register_interface( &creation_,   INTERFACE_ITEM );
    events_.register_interface( &pause_,      INTERFACE_PAUSE );
    events_.register_interface( &over_,       INTERFACE_GAME_OVER );
    events_.register_interface( &save_load_,  INTERFACE_SAVE_LOAD_MENU );

    play_data_ = new Play_Data;
    menu_.register_money( play_data_->money_addr() );


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

    while( !events_.quit() )
    {
        window_.clear();

        //text_system_->render( &txt );

        menu_.run();
        //Main game loop goes here.
        events_();

        window_.update();
    }
}



Game::~Game( void )
{

}