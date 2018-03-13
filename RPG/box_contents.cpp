

#include "stdafx.h"



/*static*/ Text* Box_Contents::text_system_ = NULL;



Box_Contents::Box_Contents( void ) :
    size_{ 0, 0, 0, 0 },
    text_(NULL)
{
    if( !text_system_ )
    {
        text_system_ = new Text;
    }
}



Box_Contents::Box_Contents( const unsigned& cu ) :
    size_{ 0, 0, 0, 0 },
    text_( new Line_of_Text[ cu ] )
{
    size_.h = cu;
}



Box_Contents::Box_Contents( const string& str ) :
    Box_Contents( Uint8_t_String( str ) )
{}



Box_Contents::Box_Contents( const char cstr[] ) :
    Box_Contents( Uint8_t_String( cstr ) )
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
    size_.h = 1;

    update_width();
}



Box_Contents& Box_Contents::add_text( const char ccstr[] )
{
    return add_text( Uint8_t_String( ccstr ) );
}



Box_Contents& Box_Contents::add_text( const string& str )
{
    return add_text( Uint8_t_String( str ) );
}



Box_Contents& Box_Contents::add_text( const Uint8_t_String& u8str )
{
    text_[ size_.h - 1 ] = u8str;
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



unsigned Box_Contents::lines( void )
{
    return (unsigned)size_.h;
}



void Box_Contents::update_width( void )
{
    for( int i = 0; i < size_.h; i++ )
    {
        if( size_.w < (int)text_[ i ].text.size() )
        {
            size_.w = (int)text_[ i ].text.size();
        }
    }
}



void Box_Contents::init( Text* t )
{
    text_system_ = t;
}



void Box_Contents::enlarge_by_one( void )
{
    Line_of_Text* nwl = new Line_of_Text[ size_.h + 1 ];
    for( int i = 0; i <= size_.h; i++ )
    {
        nwl[ i ] = text_[ i ];
    }
    delete[] text_;
    text_ = nwl;
    ++size_.h;
}
