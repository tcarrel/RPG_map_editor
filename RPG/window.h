#pragma once

#include "stdafx.h"

class Window
{

public:
    Window();

    bool good( void ) { return is_good_; }
    void clear( void );
    void update( void );

    ~Window();

    SDL_Renderer* get_renderer( void ) { return renderer_; }
    SDL_Surface* get_surface( void ) { return surface_; }
    SDL_Rect get_dimensions( void );

private:
    void splash( struct Splash_screen*, unsigned );
    void set_scale( float, float );

    bool is_good_;
    Uint32 flags_;

    int width_;
    int height_;
    int bpp_;

    SDL_DisplayMode mode_;
    SDL_Window* window_;
    SDL_Surface* surface_;

    Start_SDL subsys_init_;
    static Console* console_;

    struct
    {
        int x_;
        int y_;
    } pos;

    float scale_factor_;

    struct
    {
        int x_;
        int y_;
    } draw_offset;

    float aspect_;

    SDL_Renderer* renderer_;

    SDL_Rect borders_[ 2 ];
};
