/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile

 Description:               This file defines the Projectile class.
 ******************************************************************************/

#include "Projectile.h"

Projectile::Projectile(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, 20, 20)
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

    /*if(vel.x < 40 || vel.y < 40)
    {
        state = -1;
    }*/
}

void Projectile::applyForce(int m, vect v, int dir)
{
    if(dir == 0)
    {
        v.y = vel.y * .8;   //friction
        acc.x += ((m * (v.x - vel.x)) / mass) * .8;
        acc.y += (v.y - vel.y) * .8;
    }
    else if(dir == 1)
    {
        v.x = vel.x * .8;   //friction
        acc.x += (v.x - vel.x) * .8;
        acc.y += ((m * (v.y - vel.y)) / mass) * .8;
    }
    else
    {
        acc.x += ((m * (v.x - vel.x)) / mass) * .8;
        acc.y += ((m * (v.y - vel.y)) / mass) * .8;
    }
}

