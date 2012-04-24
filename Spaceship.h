/*******************************************************************************
 Filename:                  Spaceship.h
 Classname:                 Spaceship
 
 Description:               
 ******************************************************************************/

#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include "DrawableObject.h"
#include "MechanicsObject.h"

enum dir
{
    UL = 1,
    UR = 2,
    DL = 3,
    DR = 4
};

class Spaceship : public DrawableObject, public MechanicsObject
{
    private:
        int direction;
        int startTime;
        int time;
    
    public:
        Spaceship(const char* file, int x, int y, int d, int t);

        Object*         process();
        void            draw(SDL_Surface* s);
        void            pause();
        void            unpause();
};

#endif