#pragma once

#include<vector>
using std::vector;

#include "text_line.h"
#include "box_contents.h"





/**
*   A text box contents type that displays options that the player can choose
*  from in a vertical list.
*/
class Selectable_List : public Box_Contents
{
public:
    Selectable_List( void );

    void set_heading_count( unsigned );
    void set_return_values( int* );
    void activate( void );
    void deactivate( void );

    Box_Contents& add_text( const Uint8_t_String& );

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