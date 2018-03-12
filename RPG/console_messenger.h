#pragma once

#include<SDL.h>
#include<string>

class Uint8_t_String;

using std::string;

class Console
{
public:
    Console( void );
    Console( bool );
    static void error( string, string, string );
    static void no_error( string, string, string );

    static void vb_only_no_err( string, string );

    static void vb_variable_value( string, string, unsigned );
    static void vb_variable_value( string, string, int );
    static void vb_variable_value( string, string, float );
    static void vb_variable_value( string, string, Uint8_t_String& );
    static void vb_variable_value( string, string, void* );
    static void vb_variable_value( string, string, SDL_Rect& );
    
    static void video_info( const SDL_DisplayMode& );

    static const bool& verbose( void ) { return verbose_; }

private:
    
    static void vb_variable_value( string, string&, string&, char* );
    static void hline( void );

    static bool verbose_;
    static bool first_;
#ifdef _DEBUG
    static bool val_previous_;
#endif

    static unsigned message_num_;
};