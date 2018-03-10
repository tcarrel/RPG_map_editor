#pragma once



class Scaler
{
public:
    static void init( float );

    static int scalei( const int& );
    static float scalef( const float& );
private:
    static float factor_;
};
