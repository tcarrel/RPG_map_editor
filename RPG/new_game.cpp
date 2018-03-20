

#include "stdafx.h"




New_Game_Creation::New_Game_Creation(
    Event_Manager* e,
    Window* w,
    Console* c,
    Start_Screen* s ) :
    Interface( e, c, w, INTERFACE_NEW_GAME_SETUP ),
    new_game_( new Play_Data )
{
    s->bg_image( background_, background_pos_ );
}



Interface_enum_t New_Game_Creation::type( void )
{
    return INTERFACE_NEW_GAME_SETUP;
}



void New_Game_Creation::run( void )
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
            //TODO
            break;
        default:
            exit_ = true;
        }
    }
}



Play_Data* New_Game_Creation::get_game( void )
{
    return new_game_;
}



New_Game_Creation::~New_Game_Creation( void )
{
    new_game_ = NULL;
    background_ = NULL;
}



void New_Game_Creation::do_controls( unsigned u )
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



void New_Game_Creation::character_name( int* step )
{
    Name_Character name(
        em_,
        window_,
        console_,
        background_,
        background_pos_,
        step );

    name.run();

    if( *step == 2 )
    {
        new_game_->set_main_char_name( name.get_name() );
    }
}
