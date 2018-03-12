#pragma once

class Console;

enum Interface_t;

class Interface
{
public:

    /*
    Interface( Console* c ) :
        Interface( c, _INTERFACE_BASE )
    {}*/

    Interface( Console* c, Interface_t t ) :
        console_( c ),
        ctrl_( NULL ),
        came_from_( t )
    {}

    static void set_renderer( SDL_Renderer* );

    virtual Interface_t run( void ) = 0;

    void set_source( Interface_t );
    void register_ctrl( bool* );
    virtual Interface_t which( void ) = 0;

    ~Interface( void );
protected:

    virtual void do_controls( void ) = 0;
    virtual Interface_t exit( Interface_t& ) = 0;

    static SDL_Renderer* renderer_;

    Console* console_;
    bool* ctrl_;
    bool  ctrl_previous_[ ALL_CTRL ];
    Interface_t came_from_;

private:

    Interface() {}
};