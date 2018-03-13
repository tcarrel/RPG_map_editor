#pragma once


class Play_Data;
class Interface;

enum Interface_t;


class Save_Load_Menu : public Interface
{
public:
    Save_Load_Menu( Console* );

    Interface_t run( void );

    Interface_t which( void ) { return type_; }


private:

    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

    static const Interface_t type_;
    Interface_t next_;
};