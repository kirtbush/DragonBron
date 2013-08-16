#include "Character.h"


namespace DragonBron
{

Character::Character( std::string file, SDL_Renderer * renderer )
{
    //ctor
    m_pRenderer = renderer;
    m_pTexture = DragonBron::LoadImage(file, m_pRenderer);
    x = 0;
    y = 0;
    friction = 0.1;
    accelerationX = 0.0;
    accelerationY = 0.0;
    velocityX = 0.0;
    velocityY = 0.0;
}

Character::~Character()
{
    //dtor
    SDL_DestroyTexture( m_pTexture );
}

void Character::Draw()
{
    DragonBron::ApplySurface( x, y, m_pTexture, m_pRenderer );

}

void Character::CalculateMovement()
{
    double newvelocityX = 0.0;
    double newvelocityY = 0.0;
    double time = 1.0;

    if( accelerationX < 0.0 )
    {
        accelerationX += friction;
    }
    else if( accelerationX > 0.0 )
    {
        accelerationX -= friction;
    }

    if( accelerationY < 0.0 )
    {
        accelerationY += friction;
    }
    else if( accelerationY > 0.0 )
    {
        accelerationY -= friction;
    }

    if( velocityX < 0.0 )
    {
        newvelocityX = velocityX + accelerationX * time;
    }
    else if( velocityX > 0.0 )
    {
        newvelocityX = velocityX + accelerationX * time;
    }

    if( velocityY < 0.0 )
    {
        newvelocityY = velocityY + accelerationY * time;
    }
    else if( velocityY > 0.0 )
    {
        newvelocityY = velocityY + accelerationY * time;
    }

    newvelocityY = velocityY - accelerationY * time;

    x += newvelocityX;
    y += newvelocityY;

    velocityX = newvelocityX;
    velocityY = newvelocityY;
}

void Character::ChangeAccelX(double value)
{
    accelerationX += value;

    if( accelerationX > MAXIMUM_ACCEL )
        accelerationX = MAXIMUM_ACCEL;
    else if ( accelerationX < -MAXIMUM_ACCEL )
        accelerationX = -MAXIMUM_ACCEL;
}
void Character::ChangeAccelY(double value)
{
    accelerationY += value;

    if( accelerationY > MAXIMUM_ACCEL )
        accelerationY = MAXIMUM_ACCEL;
    else if ( accelerationY < -MAXIMUM_ACCEL )
        accelerationY = -MAXIMUM_ACCEL;
}

};
