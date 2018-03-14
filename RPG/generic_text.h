#pragma once

#include "box_contents.h"



class Generic_Text : public Box_Contents
{
public:
    Generic_Text( void );

    void activate( void );
    void deactivate( void );

    Box_Contents_t type( void );

private:


};