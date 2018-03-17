

#include "stdafx.h"




/**
*   Ctor.
*/
Selectable_List::Selectable_List( unsigned spacing ) :
    Box_Contents()
{
    text_.add( new Line_of_Text( "" ) );
    selected_ = 0;
    spacing_ = ( spacing < 1 ) ? 1 : spacing;
    active_ = true;
}



/**
*   Activates the text box.  (For use with text boxes that can be commanded by
*  the player.
*/
void Selectable_List::activate( void )
{
    active_ = true;
    update_text();
}



/**
*   Deactivates the text box.  (For use with text boxes that can be commanded by
*  the player.
*/
void Selectable_List::deactivate( void )
{
    active_ = false;
    update_text();
}



/**
*   Adds options or headings to the selection box.  No ordering is performed,
*  so they must be added in the order in which they are to appear.
*/
Box_Contents& Selectable_List::add_text(
    const Uint8_t_String& u8str,
    int return_val )
{
    static int incremental_return_value = ( return_val < 0 ) ? 0 : return_val;

    Line_of_Text* lot = new Line_of_Text( u8str );

    text_. add( lot );
    selection_.push_back( lot );
    
    if( return_val < 0 )
    {
        return_values_.push_back( incremental_return_value++ );
    }
    else
    {
        return_values_.push_back( return_val );
        incremental_return_value = return_val + 1;
    }

    for( unsigned u = 0; u < spacing_ - 1; u++ )
    {
        text_.add( new Line_of_Text( "" ) );
    }

    size_.h = text_.size();
    update_width();
    update_text();

    return *this;
}



void Selectable_List::update( void*, const unsigned& )
{
    update_text();
}



/**
*   Ignores or reacts to user input.
*/
int Selectable_List::command( Control_enum_t control )
{
    switch( control )
    {
    case CTRL_A:
        return return_values_[ selected_ ];
    case CTRL_DOWN:
        down();
        break;
    case CTRL_UP:
        up();
        break;
    default:
        ;
    }
    update_text();
    return MENU_RETURN_VALUE__NO_RETURN;
}



/**
*   Returns the enum value representing this text box type.
*/
Box_Contents_enum_t Selectable_List::type( void )
{
    return BOX_TEXT_SELECTABLE_LIST;
}



Selectable_List::~Selectable_List( void )
{
    for( unsigned u = 0; u < selection_.size(); u++ )
    {
        selection_[ u ] = NULL;
    }
    selection_.clear();
}



/**
*   moves the cursor about.
*/
void Selectable_List::update_text( void )
{
    for( unsigned u = 0; u < selection_.size(); u++ )
    {
        selection_[ u ]->hl =
            ( active_ && ( u == selected_ ) ) ?
            TEXT_HIGHLIGHT_TYPE_BRIGHT :
            TEXT_HIGHLIGHT_TYPE_NORMAL;
    }
}



void Selectable_List::down( void )
{
    ++selected_;
    if( selected_ >= selection_.size() )
    {
        selected_ = 0;
    }
}



void Selectable_List::up( void )
{
    if( selected_ == 0 )
    {
        selected_ = selection_.size() - 1;
        return;
    }
    --selected_;
}
