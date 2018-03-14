

#include "stdafx.h"



Generic_Text::Generic_Text( void ) :
    Box_Contents()
{}



void Generic_Text::activate( void )
{}



void Generic_Text::deactivate( void )
{}



Box_Contents_t Generic_Text::type( void )
{
    return BOX_GENERIC_TEXT;
}
