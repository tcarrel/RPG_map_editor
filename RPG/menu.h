#pragma once

class Interface;
class Console;

class Money_Display;
class Text_Box;

class Play_Data;

enum Interface_t;


class Menu : public Interface
{
public:
    Menu( Console* );

    void register_data_store( Play_Data* );
    Interface_t run( void );

    Interface_t which( void ) { return type_; }

private:
    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

    void __update( void );
    void __render( void );

    Money_Display* funds_;
    Text_Box* funds_box_;

    Play_Data* game_data_;

    static const Interface_t type_;
    Interface_t next_;
};