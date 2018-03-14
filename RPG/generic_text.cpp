

#include "stdafx.h"



Generic_Text::Generic_Text( void ) :
    Box_Contents()
{}



void Generic_Text::activate( void )
{}



void Generic_Text::deactivate( void )
{}



/**
*   Returns the enum value representing this text box type.
*/
Box_Contents_t Generic_Text::type( void )
{
    return BOX_GENERIC_TEXT;
}
