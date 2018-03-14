#pragma once

#include "box_contents.h"



/**
*   A text box for displaying the amount of money currently in the player's
*  possession.  Will mainly be used by the game's menu system and by shops.
*/
class Money_Display : public Box_Contents
{
public:
    Money_Display( unsigned* );

    void update( void* = NULL, const unsigned& = 0);
    int command( Control_t );
    void activate( void );
    void deactivate( void );

    Box_Contents_t type( void );

private:
    unsigned* money_;
    unsigned  money_prev_;
};