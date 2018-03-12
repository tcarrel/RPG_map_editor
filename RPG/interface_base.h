#pragma once

class Console;

enum Interface_enum;

class Interface
{
public:

    /*
    Interface( Console* c ) :
        Interface( c, _INTERFACE_BASE )
    {}*/

    Interface( Console* c, Interface_enum t ) :
        console_(c),
        ctrl_(NULL)
    {}

    static void set_renderer( SDL_Renderer* );

    virtual Interface_enum run( void ) = 0;

    void set_source( Interface_enum );
    void register_ctrl( bool* );
    virtual Interface_enum which( void ) = 0;

    ~Interface( void );
protected:

    virtual void do_controls( void ) = 0;

    static SDL_Renderer* renderer_;

    Console* console_;
    bool* ctrl_;
    bool  ctrl_previous_[ ALL_CTRL ];
    Interface_enum came_from_;

private:

    Interface() {}
};