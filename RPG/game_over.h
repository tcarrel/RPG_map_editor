#pragma once

class Interface;
class Console;

enum Interface_t;


class Game_Over : public Interface
{
public:
    Game_Over( Console* );

    Interface_t run( void );

    Interface_t which( void );

private:

    /*virtual*/ void do_controls( void );
    Interface_t exit( void );

    static const Interface_t type_;
    Interface_t next_;
};