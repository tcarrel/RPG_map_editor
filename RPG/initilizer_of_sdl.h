#pragma once

class Console;

class Start_SDL
{
public:
    Start_SDL( Uint32 );
    Start_SDL( Uint32, bool& );

    bool init( Uint32 );
    
    bool good( void );

    void show_errors( void );

    ~Start_SDL( void );

private:

    static Console* console_;
    static Uint32   count_of_these_;
    static bool error_;    
};