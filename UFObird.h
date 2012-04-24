/*******************************************************************************
 Filename:                  UFOBird.h
 Classname:                 UFOBird
 
 Description:               The UFOBird class is a subclass of Projectile that
                            is abducted from the game by a UFO in the initial
                            cut-scene.
 ******************************************************************************/

#ifndef UFOBIRD_H_INCLUDED
#define UFOBIRD_H_INCLUDED

#include "Projectile.h"

class UFObird : public Projectile
{
    private:
        const char* image2;
        SDL_Surface* Spaceship;
        bool UFOactive;
    
    public:
        UFObird(const char* file,const char* file2, int x, int y, int vx, int vy);
        ~UFObird();

        void            run();
        void            draw(SDL_Surface* s);
        Object*         process();

        static int      getNumBirds(){return numBirds;}
        void            pause();
        void            unpause();
};

#endif
