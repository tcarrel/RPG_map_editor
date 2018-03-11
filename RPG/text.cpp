

#include "stdafx.h"



/*static*/ Text_Character Text::letter_[ 256 ];
/*static*/ Sprite_Sheet Text::text_;
/*static*/ bool Text::initialized_ = false;



Text::Text( void ) : Text( TEXT_NORMAL_SPRITE_SHEET_FILE_NAME )
{}



/**
*   Initializes the text rendering system.
*/
#define W (TEXT_CHARACTER_WIDTH)
#define H (TEXT_CHARACTER_HEIGHT)
#define X(x) ((x % 16) * W)
#define Y(x) ((x % 16) * H)
Text::Text( const string& sheet_path )
{
    if( !initialized_ )
    {
        initialized_ = true;
        /*
        transparent_color magic_pink;
        magic_pink.b = magic_pink.r = 0xFF;
        magic_pink.g = 0x00;
        */

        //letter_ = new Text_Character[ ALL_CHARS ];

        //text_.load( sheet_path, &magic_pink );
        text_.load( sheet_path );

        // Set the offsets for each text sprite.
        letter_[ '!' ].set( X( 0 ), Y( 0 ), W, H );
        letter_[ '\"' ].set( X( 1 ), Y( 0 ), W, H );
        letter_[ '#' ].set( X( 2 ), Y( 0 ), W, H );
        letter_[ '$' ].set( X( 3 ), Y( 0 ), W, H );
        letter_[ '%' ].set( X( 4 ), Y( 0 ), W, H );
        letter_[ '&' ].set( X( 5 ), Y( 0 ), W, H );
        letter_[ '\'' ].set( X( 6 ), Y( 0 ), W, H );
        letter_[ '(' ].set( X( 7 ), Y( 0 ), W, H );
        letter_[ ')' ].set( X( 8 ), Y( 0 ), W, H );
        letter_[ '*' ].set( X( 9 ), Y( 0 ), W, H );
        letter_[ '+' ].set( X( 10 ), Y( 0 ), W, H );
        letter_[ ',' ].set( X( 11 ), Y( 0 ), W, H );
        letter_[ '-' ].set( X( 12 ), Y( 0 ), W, H );
        letter_[ '.' ].set( X( 13 ), Y( 0 ), W, H );
        letter_[ '/' ].set( X( 14 ), Y( 0 ), W, H );
        letter_[ '0' ].set( X( 15 ), Y( 0 ), W, H );

        letter_[ '1' ].set( X( 0 ), Y( 1 ), W, H );
        letter_[ '2' ].set( X( 1 ), Y( 1 ), W, H );
        letter_[ '3' ].set( X( 2 ), Y( 1 ), W, H );
        letter_[ '4' ].set( X( 3 ), Y( 1 ), W, H );
        letter_[ '5' ].set( X( 4 ), Y( 1 ), W, H );
        letter_[ '6' ].set( X( 5 ), Y( 1 ), W, H );
        letter_[ '7' ].set( X( 6 ), Y( 1 ), W, H );
        letter_[ '8' ].set( X( 7 ), Y( 1 ), W, H );
        letter_[ '9' ].set( X( 8 ), Y( 1 ), W, H );
        letter_[ ':' ].set( X( 9 ), Y( 1 ), W, H );
        letter_[ ';' ].set( X( 10 ), Y( 1 ), W, H );
        letter_[ '<' ].set( X( 11 ), Y( 1 ), W, H );
        letter_[ '=' ].set( X( 12 ), Y( 1 ), W, H );
        letter_[ '>' ].set( X( 13 ), Y( 1 ), W, H );
        letter_[ '?' ].set( X( 14 ), Y( 1 ), W, H );
        letter_[ '@' ].set( X( 15 ), Y( 1 ), W, H );

        letter_[ 'A' ].set( X( 32 ), Y( 2 ), W, H );
        letter_[ 'B' ].set( X( 33 ), Y( 2 ), W, H );
        letter_[ 'C' ].set( X( 34 ), Y( 2 ), W, H );
        letter_[ 'D' ].set( X( 35 ), Y( 2 ), W, H );
        letter_[ 'E' ].set( X( 36 ), Y( 2 ), W, H );
        letter_[ 'F' ].set( X( 37 ), Y( 2 ), W, H );
        letter_[ 'G' ].set( X( 38 ), Y( 2 ), W, H );
        letter_[ 'H' ].set( X( 39 ), Y( 2 ), W, H );
        letter_[ 'I' ].set( X( 40 ), Y( 2 ), W, H );
        letter_[ 'J' ].set( X( 41 ), Y( 2 ), W, H );
        letter_[ 'K' ].set( X( 42 ), Y( 2 ), W, H );
        letter_[ 'L' ].set( X( 43 ), Y( 2 ), W, H );
        letter_[ 'M' ].set( X( 44 ), Y( 2 ), W, H );
        letter_[ 'N' ].set( X( 45 ), Y( 2 ), W, H );
        letter_[ 'O' ].set( X( 46 ), Y( 2 ), W, H );
        letter_[ 'P' ].set( X( 47 ), Y( 2 ), W, H );

        letter_[ 'Q' ].set( X( 48 ), Y( 3 ), W, H );
        letter_[ 'R' ].set( X( 49 ), Y( 3 ), W, H );
        letter_[ 'S' ].set( X( 50 ), Y( 3 ), W, H );
        letter_[ 'T' ].set( X( 51 ), Y( 3 ), W, H );
        letter_[ 'U' ].set( X( 52 ), Y( 3 ), W, H );
        letter_[ 'V' ].set( X( 53 ), Y( 3 ), W, H );
        letter_[ 'W' ].set( X( 54 ), Y( 3 ), W, H );
        letter_[ 'X' ].set( X( 55 ), Y( 3 ), W, H );
        letter_[ 'Y' ].set( X( 56 ), Y( 3 ), W, H );
        letter_[ 'Z' ].set( X( 57 ), Y( 3 ), W, H );
        letter_[ '[' ].set( X( 58 ), Y( 3 ), W, H );
        letter_[ '\\' ].set( X( 59 ), Y( 3 ), W, H );
        letter_[ ']' ].set( X( 60 ), Y( 3 ), W, H );
        letter_[ '^' ].set( X( 61 ), Y( 3 ), W, H );
        letter_[ '_' ].set( X( 62 ), Y( 3 ), W, H );
        letter_[ '`' ].set( X( 63 ), Y( 3 ), W, H );

        letter_[ 'a' ].set( X( 64 ), Y( 4 ), W, H );
        letter_[ 'b' ].set( X( 65 ), Y( 4 ), W, H );
        letter_[ 'c' ].set( X( 66 ), Y( 4 ), W, H );
        letter_[ 'd' ].set( X( 67 ), Y( 4 ), W, H );
        letter_[ 'e' ].set( X( 68 ), Y( 4 ), W, H );
        letter_[ 'f' ].set( X( 69 ), Y( 4 ), W, H );
        letter_[ 'g' ].set( X( 70 ), Y( 4 ), W, H );
        letter_[ 'h' ].set( X( 71 ), Y( 4 ), W, H );
        letter_[ 'i' ].set( X( 72 ), Y( 4 ), W, H );
        letter_[ 'j' ].set( X( 73 ), Y( 4 ), W, H );
        letter_[ 'k' ].set( X( 74 ), Y( 4 ), W, H );
        letter_[ 'l' ].set( X( 75 ), Y( 4 ), W, H );
        letter_[ 'm' ].set( X( 76 ), Y( 4 ), W, H );
        letter_[ 'n' ].set( X( 77 ), Y( 4 ), W, H );
        letter_[ 'o' ].set( X( 78 ), Y( 4 ), W, H );
        letter_[ 'p' ].set( X( 79 ), Y( 4 ), W, H );

        letter_[ 'q' ].set( X( 0 ), Y( 5 ), W, H );
        letter_[ 'r' ].set( X( 1 ), Y( 5 ), W, H );
        letter_[ 's' ].set( X( 2 ), Y( 5 ), W, H );
        letter_[ 't' ].set( X( 3 ), Y( 5 ), W, H );
        letter_[ 'u' ].set( X( 4 ), Y( 5 ), W, H );
        letter_[ 'v' ].set( X( 5 ), Y( 5 ), W, H );
        letter_[ 'w' ].set( X( 6 ), Y( 5 ), W, H );
        letter_[ 'x' ].set( X( 7 ), Y( 5 ), W, H );
        letter_[ 'y' ].set( X( 8 ), Y( 5 ), W, H );
        letter_[ 'z' ].set( X( 9 ), Y( 5 ), W, H );
        letter_[ '{' ].set( X( 10 ), Y( 5 ), W, H );
        letter_[ '|' ].set( X( 11 ), Y( 5 ), W, H );
        letter_[ '}' ].set( X( 12 ), Y( 5 ), W, H );
        letter_[ '~' ].set( X( 13 ), Y( 5 ), W, H );
        letter_[ ' ' ].set( X( 14 ), Y( 5 ), W, H );
        letter_[ CHAR_INVERTED_EXCLAMATION_MARK ].set( X( 15 ), Y( 5 ), W, H );
        letter_[ CHAR_INVERTED_QUESTION_MARK ].set( X( 15 ), Y( 6 ), W, H );
        letter_[ CHAR_COIN ].set( X( 0 ), Y( 6 ), W, H );
        letter_[ CHAR_HAND__LEFT ].set( X( 1 ), Y( 6 ), W, H );
        letter_[ CHAR_HAND__RIGHT ].set( X( 2 ), Y( 6 ), W, H );
        letter_[ CHAR_25_PERCENT ].set( X( 3 ), Y( 6 ), W, H );
        letter_[ CHAR_50_PERCENT ].set( X( 4 ), Y( 6 ), W, H );
        letter_[ CHAR_75_PERCENT ].set( X( 5 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_TOP_LEFT ].set( X( 6 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_TOP_RIGHT ].set( X( 7 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_BOTTOM_RIGHT ].set( X( 8 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_BOTTOM_LEFT ].set( X( 9 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_TOP ].set( X( 10 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_BOTTOM ].set( X( 11 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_LEFT ].set( X( 12 ), Y( 6 ), W, H );
        letter_[ CHAR_BOX_RIGHT ].set( X( 13 ), Y( 6 ), W, H );
        letter_[ CHAR_ARROW_UP ].set( X( 0 ), Y( 7 ), W, H );
        letter_[ CHAR_ARROW_DOWN ].set( X( 1 ), Y( 7 ), W, H );
        letter_[ CHAR_ARROW_LEFT ].set( X( 2 ), Y( 7 ), W, H );
        letter_[ CHAR_ARROW_RIGHT ].set( X( 3 ), Y( 7 ), W, H );
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

    int length = ( 90 > text->text.size() ) ? 90 : text->text.size();

    for( int c = 0; c < length; c++ )
    {
        if( iscntrl( text->text[ c ] ) )
        {
//            printf( " Breaking on char(%c, %i", c, c );
            break;
        }
        text_.render(
            text->x + ( c * TEXT_CHARACTER_WIDTH ) + TEXT_X_OFFSET,
            text->y + TEXT_Y_OFFSET,
            letter_[ text->text[ c ] ].clip() );
    }
}