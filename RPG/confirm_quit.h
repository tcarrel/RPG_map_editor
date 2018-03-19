#pragma once

class Text_Box;
class Box_Contents;
class Selection_List;
class Interface;
class Event_Manager;
class Screen_Texture;




class Confirm_Quit : public Interface
{
public:
    Confirm_Quit( Event_Manager*, Window*, Console*, SDL_Renderer* );

    void run( void );
    Interface_enum_t type( void ); //Returns the type.

    ~Confirm_Quit( void );

    friend class Event_Manager;

private:

    void do_controls( unsigned );



    Text_Box* box_;
    static Screen_Texture screen_image_;
};