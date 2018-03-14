#pragma once

class Console;

enum Interface_t;

class Interface
{
public:

    Interface( Console* c, Interface_t t ) :
        console_( c ),
        ctrl_( NULL ),
        came_from_( t )
    {}

    static void set_renderer( SDL_Renderer* ); //Sets the renderer.

    virtual Interface_t run( void ) = 0; //For supplying the necessary loop

    void set_source( Interface_t );
    void register_ctrl( bool* ); //Registers the input registers.
    virtual Interface_t type( void ); //Returns the type.

    ~Interface( void ); //Dtor.
protected:

    virtual void do_controls( void ) = 0;
    virtual Interface_t exit( void ) = 0;
    bool exit_;

    static SDL_Renderer* renderer_;

    Console* console_;
    bool* ctrl_;
    bool  ctrl_previous_[ ALL_CTRL ];
    Interface_t came_from_;

private:

    Interface() {}
};