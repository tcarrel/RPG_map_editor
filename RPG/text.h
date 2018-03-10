#pragma once

class Text_Character;
class Sprite_Sheet;
struct Line_of_Text;





class Text
{
public:
    Text( void );
    Text( const string& );

    virtual void render( Line_of_Text* text = NULL );
protected:
    //Character Dimensions: 20 x 38

    static Text_Character  letter_[ 256 ];
    static Sprite_Sheet    text_;

private:
    static bool            initialized_;

};