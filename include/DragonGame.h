#ifndef DRAGONGAME_H
#define DRAGONGAME_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"
#include "Character.h"

namespace DragonBron
{

class DragonGame
{
    public:
        DragonGame();
        virtual ~DragonGame();
        int GameLoop();
        std::vector<Character *> m_characters;
        Character *m_pBron;
    protected:
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

};
};
#endif // DRAGONGAME_H
