

#include "stdafx.h"



/*static*/ bool Random::seeded_ = false;
/*static*/ unsigned Random::seed_   = 0;



Random::Random( void )
{
    if( !seeded_ )
    {
        seed_ = (unsigned)time( NULL );
        seeded_ = true;
        srand( seed_ );
    }
}



unsigned Random::get( unsigned max )
{
    return rand() % ( max + 1 );
}



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



unsigned Random::get_seed( void )
{
    return seed_;
}



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