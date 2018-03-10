#pragma once

class Interface;
class Console;


class Game_Over : public Interface
{
public:
    Game_Over( Console* );

    Interface_enum run( void );
private:

};