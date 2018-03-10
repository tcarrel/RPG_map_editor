#pragma once

class Interface;
class Console;


class Menu : public Interface
{
public:
    Menu( Console* );

    void register_money( unsigned* );
    Interface_enum run( void );

private:

    unsigned* monay_;
};