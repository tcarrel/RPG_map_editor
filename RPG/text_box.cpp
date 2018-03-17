

#include "stdafx.h"


/*static*/ uint8_t Text_Box::fill_color_[ 4 ] = { 0x0,0x20,0x3f,0xcc };
/*static*/ SDL_Renderer* Text_Box::renderer_ = NULL;
/*static*/ bool Text_Box::initialized_ = false;



/**
*   Sets up the basic settings for a text box based the contents passed in.
*/
Text_Box::Text_Box( Box_Contents* bcp ) :
    content_( bcp )
{
    if( !Text_Box::initialized_ )
    {
        initialized_ = true;
        renderer_ = text_[ 0 ].get_renderer();
    }

    type_ = content_->type();
    update_size();
}



/**
*   Sets the fill color for all text boxes.
*/
void Text_Box::set_fill( uint8_t r, uint8_t g, uint8_t b, uint8_t a )
{
    fill_color_[ 0 ] = r;
    fill_color_[ 1 ] = g;
    fill_color_[ 2 ] = b;
    fill_color_[ 3 ] = a;
}



/**
*   Adds additional lines of text to the text box.  This will probably have to
*  be changed later to allow for images to be displayed withing textboxes.
*/
void Text_Box::add_text( const char cca[], int i )
{
    content_->add_text( cca, i );
    update_size();
}



/**
*   Adds additional lines of text to the text box.  This will probably have to
*  be changed later to allow for images to be displayed withing textboxes.
*/
void Text_Box::add_text( const string& csr, int i )
{
    content_->add_text( csr, i );
    update_size();
}



/**
*   Adds additional lines of text to the text box.  This will probably have to
*  be changed later to allow for images to be displayed withing textboxes.
*/
void Text_Box::add_text( const Uint8_t_String& cu8sr, int i )
{
    content_->add_text( cu8sr, i );
    update_size();
}



/**
*   Returns a pointer to the contents of the text box.
*/
Box_Contents* Text_Box::contents( void )
{
    return content_;
}



/**
*   Passes commands on to the text box's contents.
*/
int Text_Box::command( Control_enum_t c )
{
    return content_->command( c );
}



/**
*   Updates the text box's size, usually only called when adding additional
*  lines of text.
*/
void Text_Box::update_size( void )
{
    box_ = content_->size();
    w_ = box_.w;
    h_ = content_->lines();

    box_.x *= TEXT_CHARACTER_WIDTH;
    box_.x += TEXT_X_OFFSET;

    box_.y *= TEXT_CHARACTER_HEIGHT;
    box_.y += TEXT_Y_OFFSET;

    box_.h *= TEXT_ROW_HEIGHT;
    box_.w *= TEXT_CHARACTER_WIDTH;
}



/**
*   Render's the text box fill.
*/
void Text_Box::render_fill( void )
{
    SDL_Rect fill = box_;
    fill.x += text_[0].get_x_offset();
    fill.y += text_[0].get_y_offset();

    SDL_SetRenderDrawColor(
        renderer_,
        fill_color_[ 0 ],
        fill_color_[ 1 ],
        fill_color_[ 2 ],
        fill_color_[ 3 ] );
    SDL_RenderFillRect( renderer_, &fill );
}



/**
*   Begins the rendering process.
*/
void Text_Box::render( void )
{
    render_border();
    render_fill();

    for( unsigned u = 0; u < h_; u++ )
    {
        line_rendering_ = u;
        render( content_->get_text()->get_line( u ) );
    }
}



/**
*   Render's the box's text.
*/
void Text_Box::render( Line_of_Text* txt)
{
    for(
        unsigned ltr = 0;
        (ltr < w_) && ( ltr < txt->text.size() );
        ltr++ )
    {
        render_char( ltr, letter_[ txt->text[ ltr ] ].clip(), txt->hl );
    }
}



/**
*   Renders each individual character.
*/
void Text_Box::render_char( unsigned u, SDL_Rect* clip, unsigned hl )
{
    text_[ hl ].render(
        box_.x + ( u * TEXT_CHARACTER_WIDTH ),
        box_.y + ( line_rendering_ * TEXT_ROW_HEIGHT ),
        clip );
}



/**
*   Renders the text box border.
*/
void Text_Box::render_border( void )
{
    //Corners
    // Top left
    text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
        box_.x - TEXT_CHARACTER_WIDTH,
        box_.y - TEXT_CHARACTER_HEIGHT,
        letter_[ CHAR_BOX_TOP_LEFT ].clip() );

    // Top right
    text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
        box_.x + box_.w,
        box_.y - TEXT_CHARACTER_HEIGHT,
        letter_[ CHAR_BOX_TOP_RIGHT ].clip() );
    // Bottom left
    text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
        box_.x - TEXT_CHARACTER_WIDTH,
        box_.y + box_.h,
        letter_[ CHAR_BOX_BOTTOM_LEFT].clip() );
    // Bottom right
    text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
        box_.x + box_.w,
        box_.y + box_.h,
        letter_[ CHAR_BOX_BOTTOM_RIGHT ].clip() );
    // Top and bottom.
    for( unsigned i = 0; i < w_; i++ )
    {
        text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
            box_.x + ( i * TEXT_CHARACTER_WIDTH ),
            box_.y - TEXT_CHARACTER_HEIGHT,
            letter_[ CHAR_BOX_TOP ].clip() );
        text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
            box_.x + ( i * TEXT_CHARACTER_WIDTH ),
            box_.y + box_.h,
            letter_[ CHAR_BOX_BOTTOM ].clip() );
    }
    // Sides
    for( unsigned i = 0; i < h_; i++ )
    {
        //Left
        text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
            box_.x - TEXT_CHARACTER_WIDTH,
            box_.y + ( i * TEXT_ROW_HEIGHT ),
            letter_[ CHAR_BOX_LEFT ].clip() );
        //Right
        text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].render(
            box_.x + box_.w,
            box_.y + ( i * TEXT_ROW_HEIGHT ),
            letter_[ CHAR_BOX_RIGHT ].clip() );
    }
}