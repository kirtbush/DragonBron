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

        m_pBron = new Character( "res/dragon_right.png", renderer );
        m_characters.push_back( m_pBron );
        //background = DragonBron::LoadImage( "res/background.bmp", renderer );
     }

    DragonGame::~DragonGame()
    {
        //dtor

        SDL_DestroyRenderer( renderer );
        SDL_DestroyWindow( window );
        //SDL_Quit();
    }

    int DragonGame::GameLoop()
    {
        bool quit = false;
        int ret = 0;
        while(!quit)
        {
            //process events
            SDL_Event event;
            while( SDL_PollEvent( &event ) )
            {
                //std::cout<< "event type "<< event.type<<endl;
    //            if( event.type == SDL_QUIT )
    //                std::cout<< "Quitting!\n";
    //                return 0;
                switch ( event.type )
                {
                    case SDL_KEYDOWN:
                        switch( event.key.keysym.sym )
                        {
                            case SDLK_LEFT:
                                m_pBron->ChangeAccelX(-0.1);
                                break;
                            case SDLK_RIGHT:
                                m_pBron->ChangeAccelX(0.1);
                                break;
                            case SDLK_UP:
                                m_pBron->ChangeAccelY(-0.1);
                                break;
                            case SDLK_DOWN:
                                m_pBron->ChangeAccelY(0.1);
                                break;
                            case SDLK_ESCAPE:
                                std::cout<< "Got an escape!\n";
                                ret = 0;
                                quit = true;
                            default:
                                m_pBron->accelerationX += (-m_pBron->accelerationX *0.1);
                                m_pBron->accelerationY += (-m_pBron->accelerationY *0.1);
                                //m_pBron->accelerationX = 0.0;
                                //m_pBron->accelerationY = 0.0;
                                break;
                        }
                        break;
                    case SDL_QUIT:
                        std::cout<< "Got an escape!\n";
                        ret = 0;
                        quit = true;
                    default:
                        break;
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

            //draw the characters
            for (std::vector<Character *>::iterator iter = m_characters.begin(); iter != m_characters.end(); ++iter)
            {
                (*iter)->CalculateMovement(SCREEN_WIDTH, SCREEN_HEIGHT);
                (*iter)->Draw();
            }

            SDL_RenderPresent( renderer );


        } //end main game loop

        return ret;
    }
}

