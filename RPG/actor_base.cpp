

#include "stdafx.h"



/*static*/ unsigned Actor::last_unused_id_ = 0;



Actor::Actor( Sprite_Sheet* sheet, int qty )
{
    name_length_;
    id_ = last_unused_id_++;
}



void Actor::set_name( char* namae, int nagasa )
{

}
