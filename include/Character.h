#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "SDL.h"
#include "CommonFunctions.h"

namespace DragonBron
{
class Character
{
    public:
        Character( std::string, SDL_Renderer * renderer );
        virtual ~Character();
        void Draw();
        void CalculateMovement(double, double);
        void SetY( int );
        void SetX( int );
        int x;
        int y;
        int width;
        int height;
        double friction;
        double velocityX;
        double velocityY;
        double accelerationX;
        double accelerationY;
        void ChangeAccelX(double);
        void ChangeAccelY(double);
        void CheckVelocity(double &);
        bool CheckCollision(int, int);

    protected:
    private:
        SDL_Renderer *m_pRenderer;
        SDL_Texture *m_pTexture;

};
};

#endif // CHARACTER_H
