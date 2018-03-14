

#include "stdafx.h"



/*static*/ bool Random::seeded_ = false;
/*static*/ unsigned Random::seed_   = 0;



/**
*   Ctor seeds the RNG the first time it is called.
*/
Random::Random( void )
{
    if( !seeded_ )
    {
        seed_ = (unsigned)time( NULL );
        seeded_ = true;
        srand( seed_ );
    }
}



/**
*   Returns a random number in the range [ 0, max ).
*/
unsigned Random::get( unsigned max )
{
    return rand() % ( max + 1 );
}


/**
*   Returns a random number between v1 and v2, inclusive.
*/
unsigned Random::get( unsigned v1, unsigned v2 )
{
    if( v1 == v2 )
    {
        return v1;
    }

    unsigned min;
    unsigned max;
    if( v1 < v2 )
    {
        min = v1;
        max = v2;
    }
    else
    {
        max = v1;
        min = v2;
    }

    return min + ( rand() % ( max - min + 1 ) );
}



/**
*   Return the number used to seed the RNG so it can be stored as part of a saved
*  game.
*/
unsigned Random::get_seed( void )
{
    return seed_;
}



/**
*   For reseeding the RNG when a saved game is loaded.
*/
void Random::seed( int s )
{
    srand( (unsigned)time( NULL ) );
    unsigned x = rand() % 243;

    srand( s );
    seeded_ = true;

    for( unsigned i = 0; i < x; i++ )
    {
        seed_ += rand() % 42364;
    }

    seed_ = s;
}