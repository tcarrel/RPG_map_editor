

#include "stdafx.h"



/**
*   Sets all variables accordingly for the start of a new game.
*/
Play_Data::Play_Data( void )
{
    Random random;
    random_seed_ = random.seed();

    money_ = random.get( 500, 1500);

    for( int i = 0; i < PLAYER_CHARACTER_NAME_MAX_LENGTH; i++ )
    {
        character_name_[ i ] = 0;
    }
}


/**
*   Returns the address of the money variable.  Mostly for use with functions
*  displaying it.
*/
unsigned* Play_Data::money_addr( void )
{
    return &money_;
}



/**
*   Adds a specified amount of money.
*/
void Play_Data::money_add( unsigned amt )
{
    money_ += amt;
    variable_max<unsigned>( money_, MAX_MONEY );
}



/**
*   Adds a random amount of money between min and max.
*/
unsigned Play_Data::money_add( unsigned min, unsigned max )
{
    Random r;
    unsigned amt = r.get( min, max );
    money_add( amt );
    return amt;
}



unsigned* Play_Data::seed_addr( void )
{
    return &random_seed_;
}



void Play_Data::set_main_char_name( char* name )
{
    int i;
    for( i = 0; i < PLAYER_CHARACTER_NAME_MAX_LENGTH && name[ i ]; i++ )
    {
        character_name_[ i ] = name[ i ];
    }
    character_name_[ i ] = 0;
}
