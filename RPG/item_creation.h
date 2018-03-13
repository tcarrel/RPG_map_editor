#pragma once

class Interface;
class Console;

enum Interface_t;


class Item_Creation : public Interface
{
public:

    Item_Creation( Console* );

    Interface_t run( void );

    Interface_t which( void ) { return type_; }

private:

    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

    static const Interface_t type_;
    Interface_t next_;
};
