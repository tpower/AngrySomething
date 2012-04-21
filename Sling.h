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

#include "Object.h"
#include "DrawableObject.h"
#include "MechanicsObject.h"
#include "ControllableObject.h"
#include "Projectile.h"
#include "UFObird.h"

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

#endif // SLING_H
