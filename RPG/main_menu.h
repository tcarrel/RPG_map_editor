#pragma once

class Interface;
class Console;


class Main_Menu : public Interface
{
public:
    Main_Menu( Console* );

    Interface_enum run( void );
private:

    /*virtual*/ void do_controls( void );

};
