

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



Box_Contents::Box_Contents( const unsigned& cu ) :
    size_{ 0,0,0,0 },
    text_( new Line_of_Text[ cu ] ),
    text_qty_( cu )
{
    size_.h = cu;
}



Box_Contents::Box_Contents( const char cstr[] ) :
    Box_Contents( Uint8_t_String(cstr) )
{}



Box_Contents::Box_Contents( const Uint8_t_String& str ) :
    Box_Contents()
{
    if( text_ )
    {
        *text_ = str;
    }
    else
    {
        text_ = new Line_of_Text( str );
    }
    text_qty_ = 1;

    update_width();
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

    update_width();

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



Uint8_t_String& Box_Contents::operator[]( const unsigned& u )
{
    return text_[ u ].text;
}



Uint8_t_String& Box_Contents::operator[]( const int& i )
{
    return text_[ i ].text;
}



SDL_Rect& Box_Contents::size( void )
{
    return size_;
}



unsigned& Box_Contents::lines( void )
{
    return text_qty_;
}



void Box_Contents::update_width( void )
{
    for( unsigned u = 0; u < text_qty_; u++ )
    {
        if( size_.w < (int)text_[ u ].text.size() )
        {
            size_.w = (int)text_[ u ].text.size();
        }
    }
}