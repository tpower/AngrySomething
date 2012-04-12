/*******************************************************************************
 Filename:                  PhysicalObject.h
 Classname:                 PhysicalObject
 
 Description:               This file declares the PhysicalObject class.
 ******************************************************************************/

#ifndef PhysicalObject_H
#define PhysicalObject_H

#include <SDL/SDL.h>

#include "Object.h"
#include "Geometry.h"

enum side
{
    NO_COLLISION    = 0,
    TOP             = 1,
    TOP_RIGHT       = 2,
    RIGHT           = 3,
    BOTTOM_RIGHT    = 4,
    BOTTOM          = 5,
    BOTTOM_LEFT     = 6,
    LEFT            = 7,
    TOP_LEFT        = 8
};

class PhysicalObject : virtual public Object
{
    protected:
        Vect vel;
        Vect acc;
        int  mass;
        int  collisionSide;
    
    public:
        PhysicalObject(int x = 0, int y = 0);
        PhysicalObject(const PhysicalObject& other);
        ~PhysicalObject();
        
        PhysicalObject& operator=(const PhysicalObject& other);
    
        void    setVel(Vect v);
        void    setAcc(Vect a);
        void    setCollisionSide(int s);
        
        Vect    getVel();
        Vect    getAcc();
        int     getMass();
        int     getCollisionSide();
    
        virtual void    run();
        virtual void    applyForce(int m, Vect v, int dir = 2);
    
        void            move();
};

#endif