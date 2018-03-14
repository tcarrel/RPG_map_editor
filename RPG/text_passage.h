#pragma once

#include "text_line.h"
#include<vector>

using std::vector;




/**
*   A wrapper for vectors of Line_of_Texts.
*/
class Passage
{
public:
    Passage( void );
    Passage( const Passage& );

    void add( Line_of_Text* );

    Line_of_Text* operator[]( const unsigned& );
    Line_of_Text* operator[]( const int& );
    Line_of_Text* get_line( const unsigned& );
    Line_of_Text* get_line( const int& );

    size_t size( void );

    ~Passage( void );

private:
    vector<Line_of_Text*> text_;

};