

#include "stdafx.h"


#define NEWGAME (0)
#define CONTINUE (1)
#define SETTINGS (2)
#define QUIT (3)
#define SELECTION_QTY (4)



Start_Screen::Start_Screen( Event_Manager* em, Window* w, Console* c ) :
    Interface( em, c, w, INTERFACE_START_MENU )
{
    SDL_Surface* new_image =
        SDL_LoadBMP( START_SCREEN_BACKGROUND_IMAGE_FILENAME );
    if( !new_image )
    {
        char msg[ 256 ];
        snprintf(
            msg,
            256,
            "Unable to load image <"
            START_SCREEN_BACKGROUND_IMAGE_FILENAME
            ">: %s",
            SDL_GetError() );
        console_->error(
            "Start Screen",
            "Unable to load image <"
            START_SCREEN_BACKGROUND_IMAGE_FILENAME
            ">.",
            msg );
    }
    bg_image_ = SDL_CreateTextureFromSurface(
        window_->get_renderer(),
        new_image );
    bg_scale_pos_ = image_scaler(
        new_image,
        SCREEN_X_PIXELS,
        SCREEN_Y_PIXELS );

    bg_scale_pos_.x = ( window_->width() - bg_scale_pos_.w ) / 2;
    bg_scale_pos_.y = ( window_->height() - bg_scale_pos_.h ) / 2;

    SDL_FreeSurface( new_image );
    new_image = NULL;

    options_.add( new Line_of_Text( 0, 0, TEXT_HIGHLIGHT_TYPE_BRIGHT, "New Game" ) );
    options_.add( new Line_of_Text( 0, 1, TEXT_HIGHLIGHT_TYPE_NORMAL, "Continue" ) );
    options_.add( new Line_of_Text( 0, 2, TEXT_HIGHLIGHT_TYPE_NORMAL, "Settings" ) );
    options_.add( new Line_of_Text( 0, 3, TEXT_HIGHLIGHT_TYPE_NORMAL, "Quit" ) );
}



void Start_Screen::init( Text* text )
{
    writter_ = text;
}



void Start_Screen::run( void )
{
    needs_redraw_ = true;
    current_selection_ = 0;
    adjust_highlight();
    
    for( ; !em_->quit(); em_->process( this ) )
    {
        if( needs_redraw_ )
        {
            window_->clear();
            needs_redraw_ = false;
            SDL_RenderCopy(
                window_->get_renderer(),
                bg_image_,
                NULL,
                &bg_scale_pos_ );
            
            for( unsigned u = 0; u < 4; u++ )
            {
                writter_->render( options_[ u ] );
            }
            window_->update();
        }
    }
}


 
inline Interface_enum_t Start_Screen::type( void )
{
    return INTERFACE_START_MENU;
}



void Start_Screen::add_state_machine_nodes( Save_Load_Menu* slm )
{
    save_load_screen_ = slm;
}



Start_Screen::~Start_Screen()
{
    SDL_DestroyTexture( bg_image_ );
    bg_image_ = NULL;
}



void Start_Screen::do_controls( unsigned u )
{
    if( ctrl_previous_[ u ] && !ctrl_current_[ u ] )
    {
        switch( u )
        {
        case CTRL_UP:
            up();
            break;
        case CTRL_DOWN:
            down();
            break;
        case CTRL_A:
        case CTRL_SELECT:
        case CTRL_START:
            select();
            break;
        default:
            break;
        }
    }
}



void Start_Screen::down( void )
{
    printf( " DOWN" );

    ++current_selection_;
    if( current_selection_ >= SELECTION_QTY )
    {
      current_selection_ = 0;
    }
    adjust_highlight();
}



void Start_Screen::up( void )
{
    printf( " UP" );

    --current_selection_;
    if( 0 > current_selection_ )
    {
      current_selection_ = options_.size() - 1;
    }
    adjust_highlight();}



void Start_Screen::adjust_highlight( void )
{
    printf( "   current_selection_ = %3i\n", current_selection_ );

    needs_redraw_ = true;
    for( int i = 0; i < SELECTION_QTY; i++ )
    {
        if( i == current_selection_ )
        {
            options_[ i ]->hl = TEXT_HIGHLIGHT_TYPE_BRIGHT;
        }
        else
        {
            options_[ i ]->hl = TEXT_HIGHLIGHT_TYPE_NORMAL;
        }
    }
}



void Start_Screen::select( void )
{
    needs_redraw_ = true;
    switch( current_selection_ )
    {
    case NEWGAME:
        Console::vb_only_no_err( "Start_Screen", "New Game not implemented." );
        return;
    case CONTINUE:
        Console::vb_only_no_err( "Start_Screen", "Continue not implemented." );
        return;
    case SETTINGS:
        Console::vb_only_no_err( "Start_Screen", "Settings not implemented." );
        return;
    case QUIT:
        em_->quit_game();
        return;
    default:
        return;
    }
}



#undef NEWGAME
#undef CONTINUE
#undef SETTINGS
#undef QUIT
#undef SELECTION_QTY
