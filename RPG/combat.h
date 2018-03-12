#pragma once

class Interface;
class Console;

enum Interface_t;


class Combat : public Interface
{
public:
    Combat( Console* );

    Interface_t run( void );

    Interface_t which( void ) { return type_; }

private:

    /*virtual*/ void do_controls( void );
    Interface_t exit( Interface_t& );

    static const Interface_t type_;
};
