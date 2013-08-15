#ifndef DRAGONGAME_H
#define DRAGONGAME_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

namespace DragonBron
{

class DragonGame
{
    public:
        DragonGame();
        virtual ~DragonGame();
        int GameLoop();

    protected:
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *background;
        SDL_Texture *face;

};
};
#endif // DRAGONGAME_H
