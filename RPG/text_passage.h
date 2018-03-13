#pragma once

#include "text_line.h"
#include<vector>


using std::vector;

class Passage
{
public:
    void add( Line_of_Text* );

    Line_of_Text* operator[]( const unsigned& );
    Line_of_Text* operator[]( const int& );

    ~Passage( void );

private:
    vector<Line_of_Text*> text_;

};