

#include "stdafx.h"


/*static*/ uint8_t Text_Box::fill_color_[ 4 ] = { 0x0,0x20,0x3f,0xcc };
/*static*/ SDL_Renderer* Text_Box::renderer_ = NULL;
/*static*/ bool Text_Box::initialized_ = false;



Text_Box::Text_Box( Box_Contents* content ) :
    content_( content )
{
    if( !Text_Box::initialized_ )
    {
        initialized_ = true;
        renderer_ = text_[ 0 ].get_renderer();
    }

    box_ = content_->size();
    w_ = box_.w;
    h_ = content_->lines();

    box_.x *= TEXT_CHARACTER_WIDTH;
    box_.x += TEXT_X_OFFSET;

    box_.y *= TEXT_CHARACTER_HEIGHT;
    box_.y += TEXT_Y_OFFSET;

    box_.h *= TEXT_ROW_HEIGHT;
    box_.w *= TEXT_CHARACTER_WIDTH;

    Console::vb_variable_value( "Text_Box", "w_", w_ );
    Console::vb_variable_value( "Text_Box", "h_", h_ );
    Console::vb_variable_value( "Text_Box", "box_", box_ );
    Console::vb_variable_value( "Text_Box", "content_->size()", content_->size() );
}



void Text_Box::set_fill( uint8_t r, uint8_t g, uint8_t b, uint8_t a )
{
    fill_color_[ 0 ] = r;
    fill_color_[ 1 ] = g;
    fill_color_[ 2 ] = b;
    fill_color_[ 3 ] = a;
}



Box_Contents* Text_Box::contents( void )
{
    return content_;
}



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



void Text_Box::render( void )
{
    render_border();
    render_fill();

    for( unsigned u = 0; u < h_; u++ )
    {
        line_rendering_ = u;
        render( content_->get_text() + u );
    }
}



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



void Text_Box::render_char( unsigned u, SDL_Rect* clip, unsigned hl )
{
    text_[ hl ].render(
        box_.x + ( u * TEXT_CHARACTER_WIDTH ),
        box_.y + ( line_rendering_ * TEXT_ROW_HEIGHT ),
        clip );
}



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