#pragma once



class Command
{
public:
    Command() {}
    virtual ~Command() = 0;
    virtual void execute( void* ) = 0;

protected:
    // Pointers to interfaces.
};