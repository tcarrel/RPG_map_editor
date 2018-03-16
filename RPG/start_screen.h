#pragma once

class Interface;
class Console;
class Window;
class Event_Manager;

class Save_Load_Menu;

class Text;
#include "text_line.h"
#include "text_passage.h"

enum Interface_t;


/**
*   The initial menu that first appears when the game is loaded, after a game
*  over, or when the player exits.
*/
class Start_Screen : public Interface
{
public:
    Start_Screen( Event_Manager*, Window*, Console* ); //Ctor
    void init( Text* );

    void run( void ); //Runs the loop for this menu.

    Interface_t type( void ); //Returns the type.

    void add_state_machine_nodes( Save_Load_Menu* );

    ~Start_Screen();

    friend class Event_Manager;

private:

    void do_controls( unsigned ); //Responds to user input.
    void down( void );
    void up( void );
    void adjust_highlight( void );
    void select( void );

    Interface_t     next_; //Where to return to.
    Save_Load_Menu* save_load_screen_;
    SDL_Texture*    bg_image_;

    bool            needs_redraw_;
    SDL_Rect        bg_scale_pos_;

    Passage         options_;
    int             current_selection_;
    Text*           writter_;

    bool*           quit_;
};
