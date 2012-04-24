/*******************************************************************************
 Filename:                  PhysicalObject.h
 Classname:                 PhysicalObject

 Description:               The PhysicalObject class is a subclass of Object
                            that can move around the screen and collide with
                            other PhysicalObjects.
 ******************************************************************************/

#ifndef PhysicalObject_H
#define PhysicalObject_H

#include "Object.h"
#include "Geometry.h"

class PhysicalObject : virtual public Object
{
    protected:
        Vect    vel;
        Vect    acc;
        int     mass;
        int     collisionSide;
        int     shape;

    public:
        PhysicalObject(int vx = 0, int vy = 0);

        void    setVel(Vect v);
        void    setAcc(Vect a);
        void    setCollisionSide(int s);

        Vect    getVel();
        Vect    getAcc();
        int     getMass();
        int     getCollisionSide();
        int     getShape();

        void    move();

        virtual void    run();
        virtual void    applyForce(int m, Vect v, int dir = 2);
};

#endif
