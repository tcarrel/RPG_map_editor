

#include "stdafx.h"



/*static*/ Text* Box_Contents::text_system_ = NULL;



Box_Contents::Box_Contents( void ) :
    size_{ 0,0,0,0 },
    text_(NULL),
    text_qty_(0)
{
    if( !text_system_ )
    {
        text_system_ = new Text;
    }
}



Box_Contents::Box_Contents( const Uint8_t_String& str ) :
    Box_Contents()
{
    if( text_ )
    {
        *text_ = str;
        return;
    }
    else
    {
        text_ = new Line_of_Text( str );
    }
    text_qty_ = 1;
}



Box_Contents& Box_Contents::operator+( const Uint8_t_String& rhs )
{
    Line_of_Text* newl = new Line_of_Text[ ++text_qty_ ];
    for( unsigned u = 0; u < ( text_qty_ - 1 ); u++ )
    {
        newl[ u ] = text_[ u ];
    }
    newl[ text_qty_ - 1 ] = rhs;

    delete[] text_;
    text_ = newl;
    text_ = NULL;

    return *this;
}



Line_of_Text* Box_Contents::get_text( void )
{
    return text_;
}



Box_Contents::~Box_Contents( void )
{
    text_system_ = NULL;
    if( text_ )
    {
        delete[] text_;
    }
}



Line_of_Text& Box_Contents::operator[]( const unsigned& u )
{
    return text_[ u ];
}



Line_of_Text& Box_Contents::operator[]( const int& i )
{
    return this->operator[]( (unsigned)i );
}



SDL_Rect& Box_Contents::size( void )
{
    return size_;
}



unsigned& Box_Contents::lines( void )
{
    return text_qty_;
}