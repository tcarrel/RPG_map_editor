

#include "stdafx.h"



void Passage::add( Line_of_Text* lot )
{
    text_.push_back( lot );
}



Line_of_Text * Passage::operator[]( const unsigned& cu )
{
    return text_[ cu ];
}



Line_of_Text * Passage::operator[]( const int& ci )
{
    return text_[ ci ];
}



Passage::~Passage( void )
{
    text_.clear();
}
