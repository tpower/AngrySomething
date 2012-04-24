/*******************************************************************************
 Filename:                  Wall.h
 Classname:                 Wall
 
 Description:               This file implements the Wall class. This class
                            is an object that occupies physical space, is
                            drawn on the screen, and is an obstical that the
                            player must overcome. This variety is not
                            destroy-able in game.
 ******************************************************************************/

#ifndef WALL_H
#define WALL_H

#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MechanicsObject.h"

class Wall : public DrawableObject, public PhysicalObject,
             public MechanicsObject
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
