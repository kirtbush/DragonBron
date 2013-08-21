#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "SDL.h"
#include "SDL_image.h"

#define MAXIMUM_MOVEMENT      10
#define MAXIMUM_ACCEL         2.0
#define MAXIMUM_VELOCITY      3.0

namespace DragonBron
{
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Texture * LoadImage( std::string file, SDL_Renderer *renderer );
void ApplySurface( int x, int y, SDL_Texture *tex, SDL_Renderer *renderer );

}

#endif // COMMONFUNCTIONS_H
