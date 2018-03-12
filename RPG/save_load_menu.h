#pragma once


class Play_Data;
class Interface;

enum Interface_enum;


class Save_Load_Menu : public Interface
{
public:
    Save_Load_Menu( Console* );

    Interface_enum run( void );

    Interface_enum which( void ) { return type_; }


private:

    /*virtual*/ void do_controls( void );

    static const Interface_enum type_;
};