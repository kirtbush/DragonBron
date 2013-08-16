#include "CommonFunctions.h"
#include "SDL_image.h"

namespace DragonBron
{
    SDL_Texture * LoadImage( std::string file, SDL_Renderer *renderer )
    {
        SDL_Texture *texture = NULL;

        texture = IMG_LoadTexture(renderer, file.c_str());
        if( texture == NULL )
        {
            throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
        }

        return texture;
    }

    void ApplySurface( int x, int y, SDL_Texture *tex, SDL_Renderer *renderer )
    {
        SDL_Rect pos;
        pos.x = x;
        pos.y = y;
        SDL_QueryTexture( tex, NULL, NULL, &pos.w, &pos.h );
        SDL_RenderCopy( renderer, tex, NULL, &pos );
    }

}
