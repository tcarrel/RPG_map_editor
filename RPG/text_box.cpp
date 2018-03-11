

#include "stdafx.h"


/*static*/ uint8_t Text_Box::fill_color_[ 4 ] = { 0x0,0x0,0xff,0x3f };
/*static*/ SDL_Renderer* Text_Box::renderer_ = NULL;
/*static*/ bool Text_Box::initialized_ = false;



Text_Box::Text_Box( int x, int y, Line_of_Text* text, int lines ) :
    h_(lines),
    words_( text )
{
    if( !Text_Box::initialized_ )
    {
        initialized_ = true;
        renderer_ = text_.get_renderer();
    }

    box_.x = x * TEXT_CHARACTER_WIDTH + TEXT_X_OFFSET;
    box_.y = y * TEXT_ROW_HEIGHT + TEXT_Y_OFFSET;
    box_.h = h_ * TEXT_ROW_HEIGHT;
    box_.w = 0;

    Console::vb_variable_value( "Text_box", "words_[0].text.size", words_[0].text.size() );

    for( int i = 0; i < h_; i++ )
    { 

        int size = words_[ i ].text.size();
#if 0        
        Console c;
        c.vb_variable_value( "Text_Box", "ctor::i", i );
        char var[32];
        snprintf( var, 32, "ctor::words_[%i].size", i );
        c.vb_variable_value( "Text_Box", var, words_[ i ].size );
#endif

        box_.w = ( box_.w < size ) ? size : box_.w;
    }
    w_ = box_.w;
    box_.w *= TEXT_CHARACTER_WIDTH;

    Console::vb_variable_value( "Text_Box", "box_", box_ );
}



void Text_Box::set_fill( uint8_t r, uint8_t g, uint8_t b, uint8_t a )
{
    fill_color_[ 0 ] = r;
    fill_color_[ 1 ] = g;
    fill_color_[ 2 ] = b;
    fill_color_[ 3 ] = a;
}



void Text_Box::render_fill( void )
{
    SDL_Rect fill = box_;
    fill.x += text_.get_x_offset();
    fill.y += text_.get_y_offset();
    SDL_SetRenderDrawColor(
        text_.get_renderer(),
        fill_color_[ 0 ],
        fill_color_[ 1 ],
        fill_color_[ 2 ],
        fill_color_[ 3 ] );
    SDL_RenderFillRect( text_.get_renderer(), &fill );
}



void Text_Box::render( Line_of_Text* )
{
    render_border();
    render_fill();

    for( int line = 0; line < h_; line++ )
    {
        for( unsigned ltr = 0; ltr < words_[line].text.size(); ltr++ )
        {
            text_.render(
                box_.x + ( ltr * TEXT_CHARACTER_WIDTH ),
                box_.y + ( line * TEXT_ROW_HEIGHT ),
                letter_[ (uint8_t)words_[ line ].text[ ltr ] ].clip() );
        }
    }

}



void Text_Box::render_border( void )
{
    //Corners
    // Top left
    text_.render(
        box_.x - TEXT_CHARACTER_WIDTH,
        box_.y - TEXT_CHARACTER_HEIGHT,
        letter_[ CHAR_BOX_TOP_LEFT ].clip() );

    // Top right
    text_.render(
        box_.x + box_.w,
        box_.y - TEXT_CHARACTER_HEIGHT,
        letter_[ CHAR_BOX_TOP_RIGHT ].clip() );
    // Bottom left
    text_.render(
        box_.x - TEXT_CHARACTER_WIDTH,
        box_.y + box_.h,
        letter_[ CHAR_BOX_BOTTOM_LEFT].clip() );
    // Bottom right
    text_.render(
        box_.x + box_.w,
        box_.y + box_.h,
        letter_[ CHAR_BOX_BOTTOM_RIGHT ].clip() );
    // Top and bottom.
    for( int i = 0; i < w_; i++ )
    {
        text_.render(
            box_.x + ( i * TEXT_CHARACTER_WIDTH ),
            box_.y - TEXT_CHARACTER_HEIGHT,
            letter_[ CHAR_BOX_TOP ].clip() );
        text_.render(
            box_.x + ( i * TEXT_CHARACTER_WIDTH ),
            box_.y + box_.h,
            letter_[ CHAR_BOX_BOTTOM ].clip() );
    }
    // Sides
    for( int i = 0; i < h_; i++ )
    {
        //Left
        text_.render(
            box_.x - TEXT_CHARACTER_WIDTH,
            box_.y + ( i * TEXT_ROW_HEIGHT ),
            letter_[ CHAR_BOX_LEFT ].clip() );
        //Right
        text_.render(
            box_.x + box_.w,
            box_.y + ( i * TEXT_ROW_HEIGHT ),
            letter_[ CHAR_BOX_RIGHT ].clip() );
    }
}