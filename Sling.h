/*******************************************************************************
 Filename:                  Sling.h
 Classname:                 Sling

 Description:               This file declares the Sling class. This class
                            is an object capable of taking user input to direct
                            the slings angle, and spawn a bird at the proper
                            velocity and position.
 ******************************************************************************/

#ifndef SLING_H
#define SLING_H

#include <string>
#include <cmath>

#include "Object.h"
#include "DrawableObject.h"
#include "MechanicsObject.h"
#include "Projectile.h"

using namespace std;

class Sling : public DrawableObject, public MechanicsObject
{
    private:
        double          radius;
        bool            checkBounds(SDL_Event);
        Projectile*     createMonkey(char type, int, int, int, int);
        SDL_Rect        Slingshot;
        string          projectiles;
        static int      projectileCount;
        SDL_Surface*    launcherImg;

    public:
        Sling(const char* file1, int x, int y, string ammo);
        ~Sling();

        Object*     handle(SDL_Event);
        void        draw(SDL_Surface*);
        static int  getProjectileCount(){ return projectileCount;}
};

#endif // SLING_H
