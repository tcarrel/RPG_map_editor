

#include "stdafx.h"



/**
*   Sets all variables accordingly for the start of a new game.
*/
Play_Data::Play_Data( void )
{
    Random random;
    random_seed_ = random.seed();

    money_ = random.get( 500, 1500);

    for( int i = 0; i < MAX_CHARACTER_NAME_LENGTH; i++ )
    {
        character_name_[ i ] = 0;
    }
    character_name_storage_size_ =
        character_name_length_ = MAX_CHARACTER_NAME_LENGTH;
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



void Play_Data::set_main_char_name( Name_Character& namer )
{
    namer.copy_name( character_name_, character_name_length_ );
}



void Play_Data::debug_print( void )
{
#ifdef _DEBUG
    for( int i = 0; i < 80; i++ )
    {
        printf( "=" );
    }
    printf( "\nPlay Data printout :\n" );
    char obj[] = "Play_Data";
    Console::vb_variable_value( obj, "random_seed_", random_seed_ );
    Console::vb_variable_value( obj, "money_", money_ );
    printf( "\t      \tPlay_Data::character_name_ = %s\n", character_name_ );
    Console::vb_variable_value(
        obj, "character_name_length", character_name_length_ );
    Console::vb_variable_value(
        obj, "character_name_storage_size_", character_name_storage_size_ );
#endif
}
