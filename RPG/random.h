#pragma once





/**
*   For requesting random numbers.  Auto seeds the RNG and ensures it only
*  gets seeded once.
*/
class Random
{
public:
    Random();
    
    unsigned get( unsigned );
    unsigned get( unsigned, unsigned );
    bool     get_bool( void );

    static unsigned seed( unsigned = 0 );

private:
    static bool seeded_;
    static unsigned  seed_;
};

#define RANDOM_DIRECTION int_to_cardinal( (int)Random::get( ALL_DIRECTIONS ) )
