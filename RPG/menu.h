#pragma once

class Interface;
class Console;

class Money_Display;
class Text_Box;

class Play_Data;

class Menu : public Interface
{
public:
    Menu( Console* );

    void register_data_store( Play_Data* );
    Interface_enum run( void );


private:
    /*virtual*/ void do_controls( void );

    void __update( void );
    void __render( void );

    Money_Display* funds_;
    Text_Box* funds_box_;

    Play_Data* game_data_;
};