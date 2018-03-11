

#include "stdafx.h"



Line_of_Text::Line_of_Text( void )
{
    this->x = this->y = 0;
    this->text = "";
}



Line_of_Text::Line_of_Text( const Uint8_t_String& str )
{
    this->x = this->y = 0;
    this->text = str;
}



Line_of_Text::Line_of_Text( const char cstr[] )
{
    *this = cstr;
}



Line_of_Text::Line_of_Text( const Line_of_Text& copy_from )
{
    *this = copy_from;
}



Line_of_Text& Line_of_Text::operator=( const Uint8_t_String& str )
{
    this->text = str;
    return *this;
}



Line_of_Text& Line_of_Text::operator=( const char cstr[] )
{
    this->text = cstr;
    return *this;
}



Line_of_Text& Line_of_Text::operator=( const Line_of_Text& rhs )
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->text = rhs.text;
    return *this;
}