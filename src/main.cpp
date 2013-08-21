#include <iostream>
#include <windows.h>
#include "DragonGame.h"

using namespace std;
using namespace DragonBron;

int main( int argc, char* args[] )
{
    DragonGame *game = new DragonGame();
    int ret = 0;

    ret = game->GameLoop();

    std::cout << "GameLoop returned "<< ret<< endl;

    return ret;
}
