

#include "stdafx.h"


Money_Display::Money_Display( unsigned* money_addr ) :
    Box_Contents( "$99,999,999" ),
    money_( money_addr )
{
    money_prev_ = *money_ + 100;

    size_.h = 1;
    size_.w = 11;
    size_.x = TEXT_COLUMNS - 11;
    size_.y = TEXT_ROWS - 1;

    text_[ 0 ].hl = TEXT_HIGHLIGHT_TYPE_NORMAL;
}



void Money_Display::update( void*, const unsigned& )
{
    assert( money_ != NULL );

    if( money_prev_ == *money_ )
    {
        return;
    }

    money_prev_ = *money_;
    char str[ 12 ];

    if( *money_ < 1000 )
    {
        snprintf(
            str,
            12,
            "%c%10i",
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
            12,
            "%c%6i,%03i",
            CHAR_COIN,
            *money_ / 1000,
            *money_ % 1000
        );
        text_[ 0 ] = str;
        return;
    }

    snprintf(
        str,
        12,
        "%c%2i,%03i,%03i",
        CHAR_COIN,
        *money_ / 1000000,
        ( *money_ % 1000000 ) / 1000,
        *money_ % 1000 );
    text_[ 0 ] = str;
}


/**
*  Takes no commands.
*/
void Money_Display::command( Control_t )
{}
