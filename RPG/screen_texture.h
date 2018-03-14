#pragma once


#include<SDL.h>



/**
*   A class for storing the entire contents of the screen, necessary for
*  displaying a screen generated from other interfaces behind the current one.
*/
class Screen_Texture
{
public:
    Screen_Texture( void );
    
    void render( void );
    static void update( void );
    static void init( Window* );

    ~Screen_Texture( void );

private:
    static void destroy( void );

    static SDL_Texture* texture_;
    static SDL_Surface* surface_;
    static SDL_Renderer* renderer_;
    static Uint32 format_;
    static bool ready_;

};