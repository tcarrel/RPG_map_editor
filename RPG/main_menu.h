#pragma once

class Interface;
class Console;

enum Interface_enum;


class Main_Menu : public Interface
{
public:
    Main_Menu( Console* );

    Interface_enum run( void );

    Interface_enum which( void ) { return type_; }

private:

    /*virtual*/ void do_controls( void );

    static const Interface_enum type_;
};
