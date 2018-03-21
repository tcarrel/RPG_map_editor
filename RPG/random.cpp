

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
        seed();
        seeded_ = true;
    }
}



/**
*   Returns a random number in the range [ 0, max ).
*/
unsigned Random::get( unsigned max )
{
    return rand() % max;
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



bool Random::get_bool( void )
{
    if( get( 2 ) )
    {
        return true;
    }
    return false;
}



/**
*   For reseeding the RNG when a saved game is loaded.
*/
unsigned Random::seed( unsigned s )
{
    if( seeded_ )
    {
        return seed_;
    }

    if( s != 0 && s == seed_ )
    {
        return seed_;
    }

    if( s == 0 )
    {
        seed_ = (unsigned)time( NULL );
        srand( seed_ );
        return seed_;
    }

    srand( (unsigned)time( NULL ) );
    unsigned x = rand() % 243;

    srand( s );
    seeded_ = true;


    for( unsigned i = 0; i < x; i++ )
    {
        seed_ += rand() % 42364;
    }

    seed_ = s;
    return seed_;
}