/*******************************************************************************
 Filename:                  Sling.h
 Classname:                 Sling

 Description:               The Sling class is an object that receives user
                            input and launches Projectiles across the screen.
 ******************************************************************************/

#ifndef SLING_H
#define SLING_H

#include <string>

#include "Object.h"
#include "DrawableObject.h"
#include "MechanicsObject.h"
#include "ControllableObject.h"
#include "Projectile.h"

using namespace std;

class Sling : public DrawableObject, public MechanicsObject, public ControllableObject
{
    private:
        double          radius;
        bool            checkBounds(SDL_Event);
        bool            grabbed;
        bool            fired;
        Projectile*     monk;
        Projectile*     createMonkey(char type, int, int, int, int);
        SDL_Rect        Slingshot;
        string          projectiles;
        static int      projectileCount;
        SDL_Surface*    launcherImg;
        int             centerX;
        int             centerY;

    public:
        Sling(const char* file1, int x, int y, string ammo);
        ~Sling();

        void        handle(SDL_Event);
        Object*     process();
        void        draw(SDL_Surface*);

        static int  getProjectileCount(){ return projectileCount;}
        void        pause();
        void        unpause();
};

#endif
