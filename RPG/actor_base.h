#pragma once


class Sprite_Sheet;
class Sprite;



class Actor
{
public:
    Actor( Sprite_Sheet*, int );
    void set_name( char*, int );

protected:

    static unsigned last_unused_id_;
    unsigned id_;

    char name_[ MAX_CHARACTER_NAME_LENGTH ];
    int  name_length_;

    int x_;
    int y_;

    int frame_qty_;


    Sprite** sprites_;

};
