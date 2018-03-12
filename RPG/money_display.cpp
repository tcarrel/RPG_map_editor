

#include "stdafx.h"

/*static*/ const char Money_Display::format_[] = "%c %3i%c%3i%c%3i";

Money_Display::Money_Display( unsigned* money_addr ) :
    Box_Contents( "$-99,999,999" ),
    money_( money_addr )
{
    money_prev_ = *money_ + 100;

    size_.h = 1;
    size_.w = 12;
    size_.x = TEXT_COLUMNS - 12;
    size_.y = TEXT_ROWS - 1;

}



void Money_Display::update( void*, const unsigned& )
{
    assert( money_ != NULL );

    if( money_prev_ != *money_ )
    {
        money_prev_ = *money_;

        char commas[ 2 ] = 
        {
            ( *money_ > 999 ) ? ',' : ' ',
            ( *money_ > 999999 ) ? ',' : ' '
        };

        unsigned ones = *money_ % 1000;
        unsigned thousands = ( *money_ % 1000000 ) / 1000;
        unsigned millions = *money_ / 1000000;

        printf( "%i\n", *money_ );
        printf( format_, CHAR_COIN, millions, commas[ 1 ], thousands, commas[ 0 ], ones );
        printf( "\n" );

        char str[ 15 ];

        if( *money_ < 1000 )
        {
            snprintf(
                str,
                15,
                "%c %10i",
                CHAR_COIN,
                *money_
            );
            text_[ 0 ] = str;
            return;
        }

        if( *money_ < 1000000 )
        {
            snprintf(
                str,
                15,
                "%c %6i,%03i",
                CHAR_COIN,
                *money_ / 1000,
                *money_ % 1000
            );
            text_[ 0 ] = str;
            return;
        }

        snprintf(
            str,
            15,
            "%c %2i,%03i,%03i",
            CHAR_COIN,
            *money_ / 1000000,
            ( *money_ % 1000000 ) / 1000,
            *money_ % 1000 );
        text_[ 0 ] = str;
    }

}