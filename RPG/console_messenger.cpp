

#include "stdafx.h"



/*static*/ bool Console::verbose_   = false;
/*static*/ bool Console::first_     = true;
/*static*/ unsigned Console::message_num_ = 1;
#ifdef _DEBUG
/*static*/ bool Console::val_previous_ = false;
#endif


Console::Console( void )
{
    if( first_ )
    {
        printf( ".\n" );
        first_ = false;
    }
}


/**
*   Can, optionally, activate a verbose output more for sending messages to the
*  console.
*/
Console::Console( bool v )
{
    if( first_ )
    {
        printf( ".\n" );
        first_ = false;
    }
    verbose_ = v;
    no_error( "Console", "Verbose:\tno", "Verbose:\tyes" );
}



/**
*   Sends an error message to the console.
*/
/*static*/ void Console::error( string source, string shrt_msg, string long_msg )
{
#ifdef _DEBUG
    if( val_previous_ )
    {
        hline();
        val_previous_ = false;
    }
#endif

    fprintf(
        stderr,
        "(%u)\n"
        "\tMessage:\n"
        "\t\tSource\t%s\n"
        "\t\tError\tyes\n"
        "\t\t\t%s\n",
        message_num_++,
        source.c_str(),
        (verbose_ ? long_msg : shrt_msg).c_str()
    );
    hline();
}



/*static*/ void Console::no_error( string source, string shrt_msg, string long_msg )
{
#ifdef _DEBUG
    if( val_previous_ )
    {
        hline();
        val_previous_ = false;
    }
#endif

    printf(
        "(%u)\n"
        "\tMessage:\n"
        "\t\tSource\t%s\n"
        "\t\tError\tno\n"
        "\t\t\t%s\n",
        message_num_++,
        source.c_str(),
        ( verbose_ ? long_msg : shrt_msg ).c_str()
    );
    hline();
}



/*static*/ void Console::vb_only_no_err( string source, string msg )
{
    if( !verbose_ )
    {
        return;
    }

#ifdef _DEBUG
    if( val_previous_ )
    {
        hline();
        val_previous_ = false;
    }
#endif

    printf(
        "(%u)\n"
        "\tMessage:\n"
        "\t\tSource\t%s\n"
        "\t\tError\tno\n"
        "\t\t\t%s\n",
        message_num_++,
        source.c_str(),
        msg.c_str()
    );
    hline();
}



#ifdef _DEBUG
/*static*/ void Console::vb_variable_value( string object, string var, unsigned value)
{
    if( !verbose_ )
    {
        return;
    }

    char str[ 33 ];
    snprintf( str, 33, "%u // 0x%x", value, value );
    vb_variable_value( "unsigned", object, var, str );
}



/*static*/ void Console::vb_variable_value( string object, string var, int value )
{
    if( !verbose_ )
    {
        return;
    }

    char str[ 33 ];
    snprintf( str, 33, "%i // 0x%x", value, value );
    vb_variable_value( "int", object, var, str );
}




/*static*/ void Console::vb_variable_value( string object, string var, void* addr )
{
    if( !verbose_ )
    {
        return;
    }

    if( !val_previous_ )
    {
        printf( "(%u)\n\tVariable Values:\n", message_num_++ );
        val_previous_ = true;
    }

    printf(
        "\t      \tpointer %s::%s = 0x%p\n",
        object.c_str(), var.c_str(), addr );
}



/*static*/ void Console::vb_variable_value( string object, string var, float val )
{
    if( !verbose_ )
    {
        return;
    }

    char str[ 33 ];
    snprintf( str, 33, "%f // 0x%x", val, *(int*)&val );
    vb_variable_value( "int", object, var, str );
}


/*static*/ void Console::vb_variable_value(
    string object,
    string var,
    Uint8_t_String& str )
{
    if( !verbose_ )
    {
        return;
    }

    printf( "\t      \tUint8_t_String %s::%s = %s\n",
            object.c_str(),
            var.c_str(),
            str.c_str() );
}



/*static*/ void Console::vb_variable_value( string object, string name, SDL_Rect& rect)
{
    if( !verbose_ )
    {
        return;
    }

    if( !val_previous_ )
    {
        printf( "(%u)\n\tVariable Values:\n", message_num_++ );
        val_previous_ = true;
    }

    printf( "\t      \tSDL_Rect %s::%s {\n", object.c_str(), name.c_str() );
    printf( "\t      \t\tx = %i\n", rect.x );
    printf( "\t      \t\ty = %i\n", rect.y );
    printf( "\t      \t\tw = %i\n", rect.w );
    printf( "\t      \t\th = %i }\n", rect.h );
}



/*static*/ void Console::vb_variable_value( string type, string& o, string& v, char* c )
{
    if( !val_previous_ )
    {
        printf( "(%u)\n\tVariable Values:\n", message_num_++ );
        val_previous_ = true;
    }
    printf(
        "\t      \t%s %s::%s = %s\n",
        type.c_str(), o.c_str(), v.c_str(), c );
}
#else
/*static*/ void Console::vb_variable_value( string, string, unsigned ) {}
/*static*/ void Console::vb_variable_value( string, string, int ) {}
/*static*/ void Console::vb_variable_value( string, string, float ) {}
/*static*/ void vb_variable_value( string, string, Uint8_t_String& ) {}
/*static*/ void Console::vb_variable_value( string, string, SDL_Rect& ) {}
/*static*/ void Console::vb_variable_value( string, string, void* ) {}
/*static*/ void Console::vb_variable_value( string, string&, string&, char* ) {}
#endif




/*static*/ void Console::video_info( const SDL_DisplayMode& mode )
{
    if( !verbose_ )
    {
        return;
    }

#ifdef _DEBUG
    if( val_previous_ )
    {
        hline();
        val_previous_ = false;
    }
#endif

    char msg[ 1024 ];
    snprintf( msg, 1024,
              "+===================+===========================+\n"
              "\t\t\t| Resolution        | %dx%d\t\t\t|\n"
              "\t\t\t| BPP               | %d\t\t\t|\n"
              "\t\t\t| Format            | %d\t\t\t|\n"
              "\t\t\t| Pixel Format Name | %s\t|\n"
              "\t\t\t+===================+===========================+\n\n",
              mode.w, mode.h, SDL_BITSPERPIXEL( mode.format ), mode.format,
              SDL_GetPixelFormatName( mode.format ) );

    no_error( "SDL2", msg, msg );
}



/*static*/ void Console::hline( void )
{
    for( unsigned i = 0; i < 80; i++ )
    {
        printf( "=" );
    }
    printf( "\n" );
}
