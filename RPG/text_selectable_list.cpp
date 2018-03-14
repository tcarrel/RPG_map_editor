

#include "stdafx.h"



Selectable_List::Selectable_List( void ) :
    Box_Contents()
{
    text_.add( new Line_of_Text( "" ) );
    selected_ = heading_qty_ = 0;
}



void Selectable_List::set_heading_count( unsigned count )
{
    heading_qty_ = count;
    selected_ = heading_qty_;
}



void Selectable_List::set_return_values( int* value_array )
{
    return_values_ = value_array;
}



void Selectable_List::activate( void )
{
    active_ = true;
}



void Selectable_List::deactivate( void )
{
    active_ = false;
}



Box_Contents& Selectable_List::add_text( const Uint8_t_String& u8str )
{
    text_.add( new Line_of_Text( u8str ) );
    text_.add( new Line_of_Text( "" ) );

    size_.h = text_.size();
    update_width();



    return *this;
}



void Selectable_List::update( void*, const unsigned& )
{}



int Selectable_List::command( Control_t control )
{
    switch( control )
    {
    case CTRL_A:
        return (return_values_) ?
            return_values_[ selected_ ] :
            selected_ - heading_qty_;
    case CTRL_DOWN:
        selected_ += 2;
        while( text_[selected_]->hl == TEXT_HIGHLIGHT_TYPE_GRAYED )
        {
            selected_ += 2;
        }
        if( selected_ > text_.size() )
        {
            selected_ = heading_qty_;
        }
        break;
    case CTRL_UP:
        selected_ -= 2;
        while( text_[ selected_ ]->hl == TEXT_HIGHLIGHT_TYPE_GRAYED )
        {
            selected_ -= 2;
        }
        if( selected_ < heading_qty_ )
        {
            selected_ = text_.size() - 2;
        }
    default:
        ;
    }
    update_text();
    return LIST_RETURN__NO_RETURN;
}



Box_Contents_t Selectable_List::type( void )
{
    return BOX_TEXT_SELECTABLE_LIST;
}



void Selectable_List::update_text( void )
{
    for( unsigned u = heading_qty_; u < text_.size(); u++ )
    {
        text_[ u ]->text[ 0 ] =
            ( active_ && ( u == selected_ ) ) ?
            CHAR_HAND__LEFT :
            ' ';
    }
}
