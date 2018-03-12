#pragma once

class Interface;
class Console;

enum Interface_enum;


class Combat : public Interface
{
public:
    Combat( Console* );

    Interface_enum run( void );

    Interface_enum which( void ) { return type_; }

private:

    /*virtual*/ void do_controls( void );

    static const Interface_enum type_;
};
