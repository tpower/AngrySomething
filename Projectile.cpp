/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile
 
 Description:               The Projectile class is an object that is launched
                            from a sling to destroy enemies.
 ******************************************************************************/

#include <cmath>

#include "Projectile.h"

int Projectile::numBirds = 0;

Projectile::Projectile(const char* file, int x, int y, int vx, int vy)
    :   Object(x, y, 20, 20),
        DrawableObject(file, 2),
        CircleObject(vx, vy)
{
    type = 1;
    numBirds++;
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
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

void Projectile::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void Projectile::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}
