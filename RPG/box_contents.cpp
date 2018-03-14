

#include "stdafx.h"



/*static*/ Text* Box_Contents::text_system_ = NULL;



Box_Contents::Box_Contents( void ) :
    size_{ 0, 0, 0, 0 }
{
    if( !text_system_ )
    {
        text_system_ = new Text;
    }
    size_.h = text_.size();
    fixed_width_ = false;
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
    text_.add( new Line_of_Text( str ) );
    size_.h = text_.size();

    update_width();
}



Box_Contents::Box_Contents( const Passage& cp ) :
    text_( cp )
{
    size_.h = text_.size();

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
    text_.add( new Line_of_Text( u8str ) );
    
    size_.h = text_.size();
    update_width();
    return *this;
}



void Box_Contents::set_position( int x, int y )
{
    size_.x = x;
    size_.y = y;
}



void Box_Contents::set_width( int w )
{
    size_.w = w;
}



Passage* Box_Contents::get_text( void )
{
    return &text_;
}



Box_Contents::~Box_Contents( void )
{
    text_system_ = NULL;
}



void Box_Contents::set_fixed_width( void )
{
    fixed_width_ = true;
}



void Box_Contents::unset_fixed_width( void )
{
    fixed_width_ = false;
}



Uint8_t_String& Box_Contents::operator[]( const unsigned& u )
{
    return text_[ u ]->text;
}



Uint8_t_String& Box_Contents::operator[]( const int& i )
{
    return text_[ i ]->text;
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
    if( fixed_width_ )
    {
        return;
    }

    for( unsigned i = 0; i < text_.size(); i++ )
    {
        if( size_.w < (int)text_[ i ]->text.size() )
        {
            size_.w = (int)text_[ i ]->text.size();
        }
    }
}



void Box_Contents::init( Text* t )
{
    text_system_ = t;
}

Box_Contents_t Box_Contents::type( void )
{
    return BOX_BOX_CONTENTS_BASE_TYPE;
}
