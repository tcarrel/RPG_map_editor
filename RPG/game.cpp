

#include "stdafx.h"
#include<cassert>


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

    events_.register_interface( &start_menu_, INTERFACE_START_MENU );
    events_.register_interface( &on_map_,     INTERFACE_MAP );
    events_.register_interface( &combat_,     INTERFACE_COMBAT );
    events_.register_interface( &menu_,       INTERFACE_MENU );
    events_.register_interface( &creation_,   INTERFACE_ITEM );
    events_.register_interface( &pause_,      INTERFACE_PAUSE );
    events_.register_interface( &over_,       INTERFACE_GAME_OVER );
    events_.register_interface( &save_load_,  INTERFACE_SAVE_LOAD_MENU );

    play_data_ = new Play_Data;
    menu_.register_money( play_data_->money() );

    Sprite_Sheet::set_renderer( renderer_ );

    text_system_ = new Text;

    pause_.init( text_system_, w );

}



Play_Data* Game::get_play_data( void )
{
    return play_data_;
}



void Game::main_loop( void )
{
    Line_of_Text txt[ 16 ];

    for( unsigned i = 0; i < 16; i++ )
    {
        txt[ i ].text = string( 16, (uint8_t)173 );
        for( unsigned j = 0; j < 16; j++ )
        {
            txt[ i ].text[ j ] = (char)( j + ( i * 16 ) );
            if( txt[ i ].text[ j ] < 32 )
            {
                txt[ i ].text[ j ] = ' ';
            }
            switch( txt[ i ].text[ j ] )
            {
            default:
                break;
            case 127:
            case '\a':
                txt[ i ].text[ j ] = '%';
                break;
            }

        }
    }

    printf( "%u\n\n", (unsigned char)'\xAD' );

    printf( "Chars:\n" );
    printf( "======\n" );
    for( int i = 0; i < 16; i++ )
    {
        for( unsigned j = 0; j < txt[ i ].text.size(); j++ )
        {
            printf( " %c = %3i\n", txt[ i ].text[ j ], (uint8_t)txt[ i ].text[ j ] );
        }
        printf( "%u\n", txt[ i ].text.size() );
    }

    for( int i = 0; i < 16; i++ )
    {
        std::cout << txt[ i ].text.c_str() << std::endl;
    }

    Text_Box box( 0, 0, txt, 16 );

    while( !events_.quit() )
    {
        window_.clear();


        //text_system_->render( &txt );
        box.render();
      //  menu_.run();
        //Main game loop goes here.
        events_();

        window_.update();
    }
}



Game::~Game( void )
{

}