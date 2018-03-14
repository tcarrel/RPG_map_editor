#pragma once



/**
*   For scaling the rendered output.
*
*   TODO:  Complete implementation.
*/
class Scaler
{
public:
    static void init( float );

    static int scalei( const int& );
    static float scalef( const float& );
private:
    static float factor_;
};
