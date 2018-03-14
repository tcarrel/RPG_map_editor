#pragma once

#include<vector>
using std::vector;

#include "text_line.h"
#include "box_contents.h"


class Selectable_List : public Box_Contents
{
public:
    Selectable_List( void );

    void set_heading_count( unsigned );
    void set_return_values( int* );
    void activate( void );
    void deactivate( void );

    void update( void* = NULL, const unsigned& = 0 );

    int command( Control_t );

    Box_Contents_t type( void );

private:

    void update_text( void );

    unsigned heading_qty_;
    unsigned selected_;
    bool allow_loop_;
    bool active_;

    int* return_values_;
};