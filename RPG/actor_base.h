#pragma once


class Sprite_Sheet;
class Sprite;



class Actor
{
public:
    Actor( Sprite_Sheet*, int );

protected:

    int x_;
    int y_;

    int frame_qty_;
    Sprite** sprites_;
};
