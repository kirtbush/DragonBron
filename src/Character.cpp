#include "Character.h"

using namespace std;

namespace DragonBron
{

Character::Character( std::string file, SDL_Renderer * renderer )
{
    //ctor
    m_pRenderer = renderer;
    m_pTexture = DragonBron::LoadImage(file, m_pRenderer);
    if(m_pTexture != NULL)
    {
        SDL_QueryTexture(m_pTexture, NULL, NULL, &width, &height);
    }
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

void Character::CalculateMovement(double windowWidth, double windowHeight)
{
    double newvelocityX = 0.0;
    double newvelocityY = 0.0;
    double time = 1.0;

//    if( accelerationX < 0.0 )
//    {
//        accelerationX += friction;
//    }
//    else if( accelerationX > 0.0 )
//    {
//        accelerationX -= friction;
//    }
//
//    if( accelerationY < 0.0 )
//    {
//        accelerationY += friction;
//    }
//    else if( accelerationY > 0.0 )
//    {
//        accelerationY -= friction;
//    }

    if( velocityX < 0.0 )
    {
        newvelocityX = velocityX + accelerationX * time;
    }
    else if( velocityX > 0.0 )
    {
        newvelocityX = velocityX + accelerationX * time;
    }
    else
    {
        newvelocityX = accelerationX * time;
    }

    if( velocityY < 0.0 )
    {
        newvelocityY = velocityY + accelerationY * time;
    }
    else if( velocityY > 0.0 )
    {
        newvelocityY = velocityY + accelerationY * time;
    }
    else
    {
        newvelocityY = accelerationY * time;
    }

    //newvelocityY = velocityY - accelerationY * time;

    cout<<__FUNCTION__ << " newvelocityX: " << newvelocityX
        << " newvelocityY: " << newvelocityY <<endl;
    cout<<__FUNCTION__ << " x: " << x
        << " y: " << y <<endl;
    cout<<__FUNCTION__ << " accelX: " << accelerationX
        << " accelY: " << accelerationY <<endl;

    CheckVelocity(newvelocityX);
    CheckVelocity(newvelocityY);

    x += newvelocityX;

    //check bounds of the game field and collision
    if(x < 0 || x + width > windowWidth || CheckCollision(x, y))
    {
        x -= newvelocityX;
        velocityX = newvelocityX = accelerationX = 0;
    }


    y += newvelocityY;
    if(y < 0 || y + height > windowHeight || CheckCollision(x, y))
    {
        y -= newvelocityY;
        velocityY = newvelocityY = accelerationY = 0;
    }



    velocityX = newvelocityX;
    velocityY = newvelocityY;
}

bool Character::CheckCollision(int x, int y)
{
    return false;
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

void Character::CheckVelocity(double &velocity)
{
    if( velocity > MAXIMUM_VELOCITY )
        velocity = MAXIMUM_VELOCITY;
    else if( velocity < -MAXIMUM_VELOCITY )
        velocity = -MAXIMUM_VELOCITY;
}

}; //namespace DragonBron
