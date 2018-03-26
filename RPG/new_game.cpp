

#include "stdafx.h"




New_Map_Creation::New_Map_Creation(
    Event_Manager* e,
    Window* w,
    Console* c,
    Start_Screen* s ) :
    Interface( e, c, w, INTERFACE_NEW_GAME_SETUP ),
    new_game_( new Play_Data )
{
    s->bg_image( background_, background_pos_ );
}



Interface_enum_t New_Map_Creation::type( void )
{
    return INTERFACE_NEW_GAME_SETUP;
}



void New_Map_Creation::run( void )
{
    exit_ = false;

    int step = 1;

    for( ; !( exit_ || em_->quit() ); em_->process( this ) )
    {
        switch( step )
        {
        case 1:
            character_name( &step );
            break;
        case 2:
            exit_ = true;
            //TODO: maybe.
            break;
        default:
            exit_ = true;
        }
    }
}



Play_Data* New_Map_Creation::get_game( void )
{
    return new_game_;
}



New_Map_Creation::~New_Map_Creation( void )
{
    new_game_ = NULL;
    background_ = NULL;
}



void New_Map_Creation::do_controls( unsigned u )
{

    switch( u )
    {
    case CTRL_B:
        exit_ = true;
        break;
    default:
        break;
    }

}



void New_Map_Creation::character_name( int* step )
{
    new_game_->set_main_char_name( Name_Character(
        em_,
        window_,
        console_,
        background_,
        background_pos_,
        step,
        true ) );
}
