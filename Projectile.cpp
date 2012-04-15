/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile

 Description:               This file defines the Projectile class.
 ******************************************************************************/

#include "Projectile.h"
#include <cmath>

int Projectile::numBirds = 0;

Projectile::Projectile(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, 50, 50)
{
    numBirds++;
}

Projectile::Projectile(const Projectile& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        Object(other.pos.x, other.pos.y)
{
    numBirds++;
}

Projectile::~Projectile()
{
    numBirds--;
}

Projectile& Projectile::operator=(const Projectile& other)
{
    if(&other != this)
    {

    }

    return *this;
}

//void Projectile::draw(SDL_Surface* screen)
//{
//
//}

void Projectile::run()
{
    move();
    
    if(pow((pow(vel.y,2) + pow(vel.x, 2)), .5) < 1)
    {
        state = -1;
    }

    //TODO: destroy object when vel drops below certain threshold
}

void Projectile::draw(SDL_Surface* screen)
{
    static SDL_Rect loc;
    loc = pos;
    
    SDL_BlitSurface(image, NULL, screen, &loc);
}

void Projectile::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

