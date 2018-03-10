

#include "stdafx.h"


/*static*/ float Scaler::factor_ = 1;



/*static*/ void Scaler::init( float f )
{
    factor_ = f;
}



/*static*/ int Scaler::scalei( const int& v )
{
    return (int)( (float)v * factor_ );
}



/*static*/ float Scaler::scalef( const float& v )
{
    return v * factor_;
}