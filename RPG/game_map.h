#pragma once

class Interface;
class Console;


class Game_Map : public Interface
{
public:
    Game_Map( Console* );

    Interface_enum run( void );
private:

};