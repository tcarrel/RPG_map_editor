#pragma once





class Play_Data
{
public:
    Play_Data( void );

    unsigned* money_addr( void );
    void add_money( unsigned );

private:

    unsigned random_seed_;
    unsigned money_;
};