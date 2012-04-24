/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile
 
 Description:               The Projectile class is an object that is launched
                            from a sling to destroy enemies.
 ******************************************************************************/

#include <cmath>

#include "Projectile.h"

int Projectile::numBirds = 0;

/*******************************************************************************
 Name:              Projectile
 Description:       Primary constructor
 
 Input:
    file            char* filepath for image file
    x               int horizontal position
    y               int vertical position
    vx              int horizontal velocity
    vy              int vertical velocity
 ******************************************************************************/
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

/*******************************************************************************
 Name:              ~Projectile
 Description:       Destructor
 ******************************************************************************/
Projectile::~Projectile()
{
    numBirds--;
}

/*******************************************************************************
 Name:              run
 Description:       This method overrides PhysicalObject::run()
 ******************************************************************************/
void Projectile::run()
{
    CircleObject::run();

    if(pow(pow(vel.y, 2.0) + pow(vel.x, 2.0), .5) < .1)
    {
        state = -1;
    }
}

/*******************************************************************************
 Name:              draw
 Description:       This method overrides DrawableObject::draw()
 
 Input:
    s               SDL_Surface* to be drawn to
 ******************************************************************************/
void Projectile::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the Projectile
 ******************************************************************************/
void Projectile::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the Projectile if it is paused
 ******************************************************************************/
void Projectile::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}
