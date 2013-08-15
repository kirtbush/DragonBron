#include "DragonGame.h"
#include "CommonFunctions.h"
#include <math.h>

using namespace std;

namespace DragonBron
{
    DragonGame::DragonGame()
    {
        //ctor
        cout << __FUNCTION__ <<  " start!\n";
        //Start SDL
        if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1)
            throw std::runtime_error("SDL_Init has Failed!");

        atexit(SDL_Quit);

        window = SDL_CreateWindow( "You are DragonBron!", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

        SDL_Surface *icon = IMG_Load( "res/dragon_icon.png" );
        SDL_SetWindowIcon( window, icon );

        background = NULL;
        face = NULL;
        //background = DragonBron::LoadImage( "res/background.bmp", renderer );
     }

    DragonGame::~DragonGame()
    {
        //dtor
        SDL_DestroyTexture( background );
        SDL_DestroyTexture( face );

        SDL_DestroyRenderer( renderer );
        SDL_DestroyWindow( window );
        //SDL_Quit();
    }

    int DragonGame::GameLoop()
    {
        //process events
        SDL_Event event;
        while( SDL_PollEvent( &event ) )
        {
            std::cout<< "event type "<< event.type<<endl;
//            if( event.type == SDL_QUIT )
//                std::cout<< "Quitting!\n";
//                return 0;
            if ( event.type == SDL_KEYDOWN )
            {
                if( event.key.keysym.scancode == SDL_SCANCODE_ESCAPE )
                {
                    std::cout<< "Got an escape!\n";
                    return 0;
                }
            }
        }

        //clear the screen
        SDL_RenderClear( renderer );

        SDL_Texture *bg1 = DragonBron::LoadImage( "res/swamp_tile_bare.png", renderer );
        SDL_Texture *bg2 = DragonBron::LoadImage( "res/swamp_tile_greenery.png", renderer );
        SDL_DisplayMode mode;
        SDL_GetCurrentDisplayMode( 0, &mode );
        int bgW = 0, bgH = 0;
        SDL_QueryTexture( bg1, NULL, NULL, &bgW, &bgH );
        int horizontalTiles = ceil(mode.w / bgW), verticalTiles = ceil(mode.h / bgH);
        for(int idx = 0; idx < horizontalTiles; idx++ )
            for(int idy = 0; idy < verticalTiles; idy++ )
                DragonBron::ApplySurface( idx*bgW, idy*bgH, bg1, renderer );

        SDL_DestroyTexture( bg1 );
        SDL_DestroyTexture( bg2 );

        SDL_RenderPresent( renderer );

        return 1;
    }
}

