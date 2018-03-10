

#include "stdafx.h"



/**
*  Adds a default ctor for Text_Character sprites.
*/
Text_Character::Text_Character( void ) :
    Sprite(
        15 * TEXT_CHARACTER_WIDTH,
        15 * TEXT_CHARACTER_HEIGHT,
        TEXT_CHARACTER_WIDTH,
        TEXT_CHARACTER_HEIGHT )
{}
