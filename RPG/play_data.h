#pragma once




/**
*    Resposible for store all gameplay data and some functions for allow this
*   data to be adjusted as necessary.
*/
class Play_Data
{
public:
    Play_Data( void );

    unsigned* money_addr( void );
    void      money_add( unsigned );
    unsigned  money_add( unsigned, unsigned );
//    bool money_subtract( void );

    unsigned* seed_addr( void );

    void set_main_char_name( char* );

private:

    unsigned random_seed_;
    unsigned money_;
    char character_name_[ PLAYER_CHARACTER_NAME_MAX_LENGTH ];
};