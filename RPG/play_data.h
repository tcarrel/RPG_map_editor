#pragma once





class Play_Data
{
public:
    Play_Data( void );

    unsigned* money_addr( void );
    void money_add( unsigned );
    unsigned money_add( unsigned, unsigned );
//    bool money_subtract( void );

private:

    unsigned random_seed_;
    unsigned money_;
};