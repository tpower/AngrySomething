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

class Projectile : public DrawableObject, public PhysicalObject, public MechanicsObject
{
    public:
        Projectile(const char* file, int x, int y, int vx, int vy);
        Projectile(const Projectile& other);
        ~Projectile();

        Projectile&     operator=(const Projectile& other);

        virtual void    draw(SDL_Surface* screen);
        virtual void    run();
        void            applyForce(int m, Vect v, int dir);
};

#endif
