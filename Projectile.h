/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile

 Description:               The Projectile class is an object that is launched
                            from a sling to destroy enemies.
 ******************************************************************************/

#ifndef AngrySomething_Projectile_h
#define AngrySomething_Projectile_h

#include "DrawableObject.h"
#include "CircleObject.h"
#include "MechanicsObject.h"

class Projectile : public DrawableObject, public CircleObject, public MechanicsObject
{
    protected:
        static int numBirds;

    public:
        Projectile(const char* file, int x, int y, int vx, int vy);
        ~Projectile();

        static int      getNumBirds() {return numBirds;}

        virtual void    run();
        void            draw(SDL_Surface* s);
        void            pause();
        void            unpause();
};

#endif
