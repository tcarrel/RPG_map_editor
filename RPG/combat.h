#pragma once

class Interface;
class Console;


class Combat : public Interface
{
public:
    Combat( Console* );

    Interface_enum run( void );
private:

    /*virtual*/ void do_controls( void );

};
