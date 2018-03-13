

#include "stdafx.h"



Passage::Passage( void )
{}



Passage::Passage( const Passage& source ) :
    text_( source.text_ )
{}



void Passage::add( Line_of_Text* lot )
{
    text_.push_back( lot );
}



Line_of_Text* Passage::operator[]( const unsigned& cu )
{
    return text_[ cu ];
}



Line_of_Text* Passage::operator[]( const int& ci )
{
    return text_[ ci ];
}



Line_of_Text* Passage::get_line( const unsigned& cu )
{
    return text_[ cu ];
}



Line_of_Text* Passage::get_line( const int& ci )
{
    return text_[ ci ];
}



size_t Passage::size( void )
{
    return text_.size();
}



Passage::~Passage( void )
{}
