/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile

 Description:               This file declares the Projectile class.
 ******************************************************************************/

#ifndef AngrySomething_Projectile_h
#define AngrySomething_Projectile_h

#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MechanicsObject.h"
#include "CircleObject.h"

class Projectile : public DrawableObject, public CircleObject, public MechanicsObject
{
    public:
        Projectile(const char* file, int x, int y, int vx, int vy);

        virtual void    draw(SDL_Surface* screen);
};

#endif
