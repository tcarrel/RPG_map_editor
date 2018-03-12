#pragma once

#include<vector>
using std::vector;

#include "text_line.h"
class Box_Contents;


class Selectable_List : public Box_Contents
{
public:
    Selectable_List( void );
    ~Selectable_List( void );

    void set_width( unsigned );

private:
    unsigned heading_qty_;
    unsigned line_qty_;
    Line_of_Text* text_;

    unsigned selected_;
};