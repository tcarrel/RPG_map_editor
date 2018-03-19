

#include "stdafx.h"



/*static*/ Sprite Text::letter_[ ALL_TEXT_HIGHLIGHT_TYPES ][ 256 ];
/*static*/ Sprite_Sheet Text::text_[ ALL_TEXT_HIGHLIGHT_TYPES ];
/*static*/ bool Text::initialized_ = false;



/**
*   Initializes the text rendering system.
*/
#define W (TEXT_CHARACTER_WIDTH)
#define H (TEXT_CHARACTER_HEIGHT)
#define X(x) ((x % 16) * W)
#define Y(x) ((x % 16) * H)
Text::Text( void )
//Text::Text( const string& sheet_path )
{
    if( !initialized_ )
    {
        initialized_ = true;
        Console::vb_variable_value( "Text", "renderer_", text_[ 0 ].get_renderer() );


        if( !text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].ready() )
        {
            text_[ TEXT_HIGHLIGHT_TYPE_NORMAL ].load(
                TEXT_NORMAL_SPRITE_SHEET_FILENAME );
        }
        if( !text_[ TEXT_HIGHLIGHT_TYPE_GRAYED ].ready() )
        {
            text_[ TEXT_HIGHLIGHT_TYPE_GRAYED ].load(
                TEXT_GRAYED_SPRITE_SHEET_FILENAME );
        }
        if( !text_[ TEXT_HIGHLIGHT_TYPE_BRIGHT].ready() )
        {
            text_[ TEXT_HIGHLIGHT_TYPE_BRIGHT ].load(
                TEXT_HIGHLIGHT_SPRITE_SHEET_FILENAME );
        }

        for( unsigned u = 0; u < ALL_TEXT_HIGHLIGHT_TYPES; u++ )
        { // Set the offsets for each text sprite.
            letter_[u][ '!' ].set( X( 0 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '\"' ].set( X( 1 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '#' ].set( X( 2 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '$' ].set( X( 3 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '%' ].set( X( 4 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '&' ].set( X( 5 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '\'' ].set( X( 6 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '(' ].set( X( 7 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ ')' ].set( X( 8 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '*' ].set( X( 9 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '+' ].set( X( 10 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ ',' ].set( X( 11 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '-' ].set( X( 12 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '.' ].set( X( 13 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '/' ].set( X( 14 ), Y( 0 ), W, H, text_ + u );
            letter_[ u ][ '0' ].set( X( 15 ), Y( 0 ), W, H, text_ + u );

            letter_[ u ][ '1' ].set( X( 0 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '2' ].set( X( 1 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '3' ].set( X( 2 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '4' ].set( X( 3 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '5' ].set( X( 4 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '6' ].set( X( 5 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '7' ].set( X( 6 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '8' ].set( X( 7 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '9' ].set( X( 8 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ ':' ].set( X( 9 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ ';' ].set( X( 10 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '<' ].set( X( 11 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '=' ].set( X( 12 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '>' ].set( X( 13 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '?' ].set( X( 14 ), Y( 1 ), W, H, text_ + u );
            letter_[ u ][ '@' ].set( X( 15 ), Y( 1 ), W, H, text_ + u );

            letter_[ u ][ 'A' ].set( X( 32 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'B' ].set( X( 33 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'C' ].set( X( 34 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'D' ].set( X( 35 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'E' ].set( X( 36 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'F' ].set( X( 37 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'G' ].set( X( 38 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'H' ].set( X( 39 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'I' ].set( X( 40 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'J' ].set( X( 41 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'K' ].set( X( 42 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'L' ].set( X( 43 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'M' ].set( X( 44 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'N' ].set( X( 45 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'O' ].set( X( 46 ), Y( 2 ), W, H, text_ + u );
            letter_[ u ][ 'P' ].set( X( 47 ), Y( 2 ), W, H, text_ + u );

            letter_[ u ][ 'Q' ].set( X( 48 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'R' ].set( X( 49 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'S' ].set( X( 50 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'T' ].set( X( 51 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'U' ].set( X( 52 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'V' ].set( X( 53 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'W' ].set( X( 54 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'X' ].set( X( 55 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'Y' ].set( X( 56 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ 'Z' ].set( X( 57 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ '[' ].set( X( 58 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ '\\' ].set( X( 59 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ ']' ].set( X( 60 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ '^' ].set( X( 61 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ '_' ].set( X( 62 ), Y( 3 ), W, H, text_ + u );
            letter_[ u ][ '`' ].set( X( 63 ), Y( 3 ), W, H, text_ + u );

            letter_[ u ][ 'a' ].set( X( 64 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'b' ].set( X( 65 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'c' ].set( X( 66 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'd' ].set( X( 67 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'e' ].set( X( 68 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'f' ].set( X( 69 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'g' ].set( X( 70 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'h' ].set( X( 71 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'i' ].set( X( 72 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'j' ].set( X( 73 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'k' ].set( X( 74 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'l' ].set( X( 75 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'm' ].set( X( 76 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'n' ].set( X( 77 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'o' ].set( X( 78 ), Y( 4 ), W, H, text_ + u );
            letter_[ u ][ 'p' ].set( X( 79 ), Y( 4 ), W, H, text_ + u );

            letter_[ u ][ 'q' ].set( X( 0 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 'r' ].set( X( 1 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 's' ].set( X( 2 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 't' ].set( X( 3 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 'u' ].set( X( 4 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 'v' ].set( X( 5 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 'w' ].set( X( 6 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 'x' ].set( X( 7 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 'y' ].set( X( 8 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ 'z' ].set( X( 9 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ '{' ].set( X( 10 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ '|' ].set( X( 11 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ '}' ].set( X( 12 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ '~' ].set( X( 13 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ ' ' ].set( X( 14 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ CHAR_INVERTED_EXCLAMATION_MARK ].set( X( 15 ), Y( 5 ), W, H, text_ + u );
            letter_[ u ][ CHAR_INVERTED_QUESTION_MARK ].set( X( 15 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_COIN ].set( X( 0 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_HAND__LEFT ].set( X( 1 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_HAND__RIGHT ].set( X( 2 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_25_PERCENT ].set( X( 3 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_50_PERCENT ].set( X( 4 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_75_PERCENT ].set( X( 5 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_TOP_LEFT ].set( X( 6 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_TOP_RIGHT ].set( X( 7 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_BOTTOM_RIGHT ].set( X( 8 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_BOTTOM_LEFT ].set( X( 9 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_TOP ].set( X( 10 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_BOTTOM ].set( X( 11 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_LEFT ].set( X( 12 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_BOX_RIGHT ].set( X( 13 ), Y( 6 ), W, H, text_ + u );
            letter_[ u ][ CHAR_ARROW_UP ].set( X( 0 ), Y( 7 ), W, H, text_ + u );
            letter_[ u ][ CHAR_ARROW_DOWN ].set( X( 1 ), Y( 7 ), W, H, text_ + u );
            letter_[ u ][ CHAR_ARROW_LEFT ].set( X( 2 ), Y( 7 ), W, H, text_ + u );
            letter_[ u ][ CHAR_ARROW_RIGHT ].set( X( 3 ), Y( 7 ), W, H, text_ + u );
        }
    }
}
#undef W
#undef H
#undef X
#undef Y


/**
*   Renders the supplied text onto the window surface.
*
*  text    : The text to be rendered in the appropriate data structure.
*/
void Text::render( Line_of_Text* text )
{
    if( !text )
    {
        return;
    }

    int length =
        ( TEXT_COLUMNS < text->text.size() ) ?
        TEXT_COLUMNS :
        text->text.size();

    for( int c = 0; ( c < length ) && ( !iscntrl( text->text[ c ] ) ); c++ )
    {
        letter_[ text->hl ][ text->text[ c ] ].render(
            text->x + ( c*TEXT_CHARACTER_WIDTH ) + TEXT_X_OFFSET,
            text->y + TEXT_Y_OFFSET );

        /*
        text_[ text->hl ].render(
            text->x + ( c * TEXT_CHARACTER_WIDTH ) + TEXT_X_OFFSET,
            text->y + TEXT_Y_OFFSET,
            letter_[ text->text[ c ] ].clip() );
            */
    }
}
