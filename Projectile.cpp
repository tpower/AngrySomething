/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile

 Description:               This file defines the Projectile class.
 ******************************************************************************/

#include "Projectile.h"

Projectile::Projectile(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        CircleObject(vx, vy),
        Object(x, y, 60, 60)
{
    
}

void Projectile::draw(SDL_Surface* screen)
{
    static SDL_Rect loc;
    loc = pos;
    
    SDL_BlitSurface(image, NULL, screen, &loc);
}

void Projectile::applyForce(int m, Vect v, int dir)
{
    CircleObject::applyForce(m, v, dir);
}

