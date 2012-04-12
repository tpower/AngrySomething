/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile

 Description:               This file defines the Projectile class.
 ******************************************************************************/

#include "Projectile.h"

Projectile::Projectile(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, 60, 60)
{
    
}

Projectile::Projectile(const Projectile& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        Object(other.pos.x, other.pos.y)
{
    
}

Projectile::~Projectile()
{
    
}

Projectile& Projectile::operator=(const Projectile& other)
{
    if(&other != this)
    {

    }

    return *this;
}

void Projectile::draw(SDL_Surface* screen)
{
    static SDL_Rect loc;
    loc = pos;
    
    SDL_BlitSurface(image, NULL, screen, &loc);
}

void Projectile::run()
{
    move();

//    if(abs(vel.x) < .5 && abs(vel.y) < .5)
//    {
//        state = -1;
//    }
}

