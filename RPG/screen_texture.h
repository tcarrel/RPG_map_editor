#pragma once


#include<SDL.h>



class Screen_Texture
{
public:
    Screen_Texture( void );
    
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