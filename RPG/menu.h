#pragma once

class Interface;
class Console;

class Money_Display;
class Text_Box;


class Menu : public Interface
{
public:
    Menu( Console* );

    void register_money( unsigned* );
    Interface_enum run( void );

private:

    void __update( void );
    void __render( void );

    Money_Display* funds_;
    Text_Box* funds_box_;
};