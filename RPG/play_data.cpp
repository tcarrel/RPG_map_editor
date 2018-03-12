

#include "stdafx.h"



Play_Data::Play_Data( void )
{
    Random random;
    random_seed_ = random.get_seed();

    money_ = random.get( 500, 1500);
}



unsigned* Play_Data::money_addr( void )
{
    return &money_;
}



void Play_Data::money_add( unsigned amt )
{
    money_ += amt;
    variable_max<unsigned>( money_, MAX_MONEY );
}



unsigned Play_Data::money_add( unsigned min, unsigned max )
{
    Random r;
    unsigned amt = r.get( min, max );
    money_add( amt );
    return amt;
}