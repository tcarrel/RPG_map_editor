#pragma once





class Random
{
public:
    Random();
    
    unsigned get( unsigned );
    unsigned get( unsigned, unsigned );

    unsigned get_seed( void );
    static void seed( int );

private:
    static bool seeded_;
    static unsigned  seed_;
};