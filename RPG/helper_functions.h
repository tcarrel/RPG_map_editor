#pragma once



template<typename T>
void variable_max( T& variable, const T&  max )
{
    if( variable > max )
    {
        variable = max;
    }
}