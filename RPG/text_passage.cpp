

#include "stdafx.h"



/**
*   Ctor.
*/
Passage::Passage( void )
{}



/**
*   Copy ctor.
*/
Passage::Passage( const Passage& source ) :
    text_( source.text_ )
{}



/**
*   Adds one line of text.
*/
void Passage::add( Line_of_Text* lot )
{
    text_.push_back( lot );
}



/**
*   Subscipt operator for array-like access.
*/
Line_of_Text* Passage::operator[]( const unsigned& cu )
{
    return text_[ cu ];
}



/**
*   Subscipt operator for array-like access.
*/
Line_of_Text* Passage::operator[]( const int& ci )
{
    return text_[ ci ];
}



/**
*   Returns the Line_of_Text specified by cu.
*/
Line_of_Text* Passage::get_line( const unsigned& cu )
{
    return text_[ cu ];
}



/**
*   Returns the Line_of_Text specified by ci.
*/
Line_of_Text* Passage::get_line( const int& ci )
{
    return text_[ ci ];
}



/**
*   Returns the size of the vector.  (Number of Line_of_Text.)
*/
size_t Passage::size( void )
{
    return text_.size();
}



/**
*   Dtor to be filled in later.
*/
Passage::~Passage( void )
{}
