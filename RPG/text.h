#pragma once

//class Text_Character;
class Sprite;
class Sprite_Sheet;
struct Line_of_Text;




/**
*   A class for managing the minimum requirements for displaying on-screen
*  sprite-based text.
*/
class Text
{
public:
    Text( void );

    virtual void render( Line_of_Text* text = NULL );

    Sprite& letter( int, int );

protected:
    //Character Dimensions: 20 x 38

    static Sprite          letter_[ ALL_TEXT_HIGHLIGHT_TYPES ][ 256 ];
    static Sprite_Sheet    text_[ ALL_TEXT_HIGHLIGHT_TYPES ];

private:
    static bool            initialized_;

};