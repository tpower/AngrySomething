/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile

 Description:               This file defines the Projectile class.
 ******************************************************************************/

#include "Projectile.h"
#include <cmath>

int Projectile::numBirds = 0;

Projectile::Projectile(const char* file, int x, int y, int vx, int vy)
    :   Object(x, y, 50, 50),
        DrawableObject(file),
        CircleObject(vx, vy)

{
    type = 1;
    numBirds++;
}

Projectile::~Projectile()
{
    numBirds--;
}

void Projectile::run()
{
    CircleObject::run();

    if(pow(pow(vel.y, 2.0) + pow(vel.x, 2.0), .5) < 1)
    {
        state = -1;
    }
}

void Projectile::draw(SDL_Surface* screen)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, screen, &loc);
}
