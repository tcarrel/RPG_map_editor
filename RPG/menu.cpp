
#include "stdafx.h"




Menu::Menu( Console* c ) :
    Interface( c, INTERFACE_MENU )
{}



void Menu::register_money( unsigned* money_ptr )
{
    monay_ = money_ptr;
}



Interface_enum Menu::run( void )
{
    SDL_Rect square;
    square.x = square.y = 32;
    square.h = square.w = 32;
    SDL_SetRenderDrawColor( renderer_, 0xff, 0, 0, 0xff );
    SDL_RenderFillRect( renderer_, &square );

    square.x = 0;  square.y = 32;
    square.h = square.w = 32;
    SDL_SetRenderDrawColor( renderer_, 0xff, 0xff, 0, 0xff );
    SDL_RenderFillRect( renderer_, &square );

    square.x = 32; square.y = 0;
    square.h = square.w = 32;
    SDL_SetRenderDrawColor( renderer_, 0, 0xff, 0, 0xff );
    SDL_RenderFillRect( renderer_, &square );

    square.x = square.y = 0;
    square.h = square.w = 32;
    SDL_SetRenderDrawColor( renderer_, 0, 0, 0xff, 0xff );
    SDL_RenderFillRect( renderer_, &square );

    return type_;
}