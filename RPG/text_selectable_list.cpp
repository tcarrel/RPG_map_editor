

#include "stdafx.h"




Selectable_List::Selectable_List( void )
{
    heading_qty_ = 0;
    line_qty_ = 0;
    selected_ = 0;
}



Selectable_List::~Selectable_List( void )
{
    if( line_qty_ )
    {
        delete[] text_;
        text_ = NULL;
    }
}



void Selectable_List::add_text( Line_of_Text* line, bool heading )
{
    line_qty_;
    if( heading )
    {
        ++heading_qty_;
    }

    Line_of_Text* new_text = new Line_of_Text[ line_qty_ + 1];
    for( unsigned i = 0; i < line_qty_; i++ )
    {
        new_text[ i ] = text_[ i ];
    }
    new_text[ line_qty_ ] = *line;

    if( line_qty_ > 0 )
    {
        delete[] text_;
    }

    text_ = new_text;
    new_text = NULL;

    ++line_qty_;
}



Line_of_Text* Selectable_List::get_text( void )
{
    return text_;
}



unsigned Selectable_List::size( void )
{
    return line_qty_;
}