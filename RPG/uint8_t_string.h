#pragma once





class Uint8_t_String
{
public:
    Uint8_t_String( void );
    Uint8_t_String( const Uint8_t_String& );
    Uint8_t_String( const char*& );

    Uint8_t_String& operator=( const Uint8_t_String& );
    Uint8_t_String& operator=( const char[] );

    uint8_t& operator[]( const unsigned& );
    uint8_t& operator[]( const int& );

    uint8_t*& c_str( void );

    unsigned size( void );

private:
    void grow( unsigned u = 0 );

    uint8_t* string_;

    unsigned length_;
    unsigned capacity_;
};