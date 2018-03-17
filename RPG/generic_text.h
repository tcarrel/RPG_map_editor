#pragma once

#include "box_contents.h"



/**
*   A type of text box, mainly to be used for display common text, like when
*  talking to NPC's.
*/
class Generic_Text : public Box_Contents
{
public:
    Generic_Text( void );

    void activate( void );
    void deactivate( void );

    Box_Contents_enum_t type( void );

private:


};