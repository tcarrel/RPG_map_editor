#pragma once

class Console;



/**
*   Initializes and quits the various SDL components.
*/
class Start_SDL
{
public:
    Start_SDL( Uint32 );
    Start_SDL( Uint32, bool& );

    bool init( Uint32 );
    
    bool good( void );

    void show_errors( void );
    
private:

    static Console* console_;
    static bool     exit_set_;
    static bool error_;    
};