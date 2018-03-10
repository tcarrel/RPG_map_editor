#pragma once

class Console;
class Window;
class Event_Manager;
class Combat;
class Game_Map;
class Menu;
class Main_Menu;
class Pause;
class Item_Creation;
class Play_Data;

class Interface;

struct SDL_Renderer;

class Game
{
public:
    Game( Console*, Window*, Event_Manager* );

    void main_loop( void );

    Play_Data* get_play_data( void );

    ~Game( void );

private:
    Start_SDL      sdl_init_;

    Console&       console_;
    Window&        window_;
    Event_Manager& events_;

    Main_Menu      start_menu_;
    Combat         combat_;
    Game_Map       on_map_;
    Menu           menu_;
    Item_Creation  creation_;
    Game_Over      over_;
    Pause          pause_;
    Save_Load_Menu save_load_;

    Play_Data*     play_data_;

    SDL_Renderer*  renderer_;
    Text*          text_system_;
};