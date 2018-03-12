

#include "stdafx.h"



/*static*/ SDL_Renderer* Interface::renderer_ = NULL;



void Interface::register_ctrl( bool* c )
{
    if( ctrl_ && console_ && console_->verbose() )
    {
        console_->error(
            "Interface",
            "",
            "Multiple registrations of control flags attempted." );
        return;
    }

    ctrl_ = c;
    for( unsigned u = 0; u < ALL_CTRL; u++ )
    {
        ctrl_previous_[ u ] = ctrl_[ u ];
    }
}



/*static*/ void Interface::set_renderer( SDL_Renderer* r )
{
    renderer_ = r;
}


void Interface::set_source( Interface_enum source )
{
    came_from_ = source;
}



Interface_enum Interface::which( void )
{
    return type_;
}



Interface::~Interface( void )
{
    ctrl_ = NULL;
}