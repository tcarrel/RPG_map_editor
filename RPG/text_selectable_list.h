#pragma once

#include<vector>
using std::vector;

#include "text_line.h"


class Selectable_List
{
public:
    Selectable_List( void );
    ~Selectable_List( void );

    void add_text( Line_of_Text*, bool );

    Line_of_Text* get_text( void );
    unsigned size( void );

private:
    unsigned heading_qty_;
    unsigned line_qty_;
    Line_of_Text* text_;
    //bool* active_;

    unsigned selected_;
};