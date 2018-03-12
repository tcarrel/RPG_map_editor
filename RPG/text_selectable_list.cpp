

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



void Selectable_List::set_width( unsigned u )
{
    size_.w = u;
}
