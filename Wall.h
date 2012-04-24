/*******************************************************************************
 Filename:                  Wall.h
 Classname:                 Wall
 
 Description:               The Wall class is an object that is used to create
                            structures and barriers within the game.
 ******************************************************************************/

#ifndef WALL_H
#define WALL_H

#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MechanicsObject.h"

class Wall : public DrawableObject, public PhysicalObject, public MechanicsObject
{
    protected:
        int health;

    public:
        Wall(const char* file, int x, int y, int vx, int vy, int w, int h);
        ~Wall();
    
        virtual void    run();
        void            applyForce(int m, Vect v, int dir);
        void            pause();
        void            unpause();
};

#endif
