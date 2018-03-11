

#include "stdafx.h"

/*static*/ const char Money_Display::format_[] = "\xa8 %9i";

Money_Display::Money_Display( unsigned* money_addr ) :
    Box_Contents(),
    money_( money_addr )
{
    
}



void Money_Display::update( void*, const unsigned& )
{
    char fill[ 12 ];
    snprintf( fill, 12, format_, *money_ );
    text_[ 0 ] = fill;
}