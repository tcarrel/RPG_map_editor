#pragma once

#include "box_contents.h"



class Money_Display : public Box_Contents
{
public:
    Money_Display( unsigned* );

    void update( void* = NULL, const unsigned& = 0);
private:
    unsigned* money_;
    unsigned money_prev_;
};