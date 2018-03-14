

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



Interface_t Interface::type( void )
{
    return _INTERFACE_BASE;
}



/*static*/ void Interface::set_renderer( SDL_Renderer* r )
{
    renderer_ = r;
}



/**
*   For storing the previous interface for so it can be returned to when
*  necessary.
*/
void Interface::set_source( Interface_t source )
{
    came_from_ = source;
}



Interface::~Interface( void )
{
    ctrl_ = NULL;
}