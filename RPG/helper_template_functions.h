#pragma once


/**
*   Helper template functions can be defined here.
*/


/**
*   If variable is greater than max its value is reset to max.
*/
template<typename T>
void variable_max( T& variable, const T&  max )
{
    if( variable > max )
    {
        variable = max;
    }
}