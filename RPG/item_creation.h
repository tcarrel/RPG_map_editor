#pragma once

class Interface;
class Console;


class Item_Creation : public Interface
{
public:

    Item_Creation( Console* );

    Interface_enum run( void );
private:

    /*virtual*/ void do_controls( void );

};
