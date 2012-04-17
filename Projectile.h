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
    private:
        static int numBirds;
    public:
        Projectile(const char* file, int x, int y, int vx, int vy);
        Projectile(const Projectile& other);
        ~Projectile();

        Projectile&     operator=(const Projectile& other);

//        virtual void    draw(SDL_Surface* screen);
        virtual void    run();
        void            draw(SDL_Surface* s);
        void            applyForce(int m, vect v, int dir);

        static int      getNumBirds(){return numBirds;}
};

#endif
