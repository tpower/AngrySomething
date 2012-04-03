/*******************************************************************************
 Filename:                  PhysicalObject.h
 Classname:                 PhysicalObject
 
 Description:               This file declares the PhysicalObject class.
 ******************************************************************************/

#ifndef PhysicalObject_H
#define PhysicalObject_H

#include <SDL/SDL.h>

#include "Object.h"

struct vect
{
    double x, y;
};

class PhysicalObject : virtual public Object
{
    protected:
        vect vel;
        vect acc;
        int  mass;
    
    public:
        PhysicalObject(int x = 0, int y = 0);
        PhysicalObject(const PhysicalObject& other);
        ~PhysicalObject();
        
        PhysicalObject& operator=(const PhysicalObject& other);
    
        void    setVel(vect v);
        void    setAcc(vect a);
        void    applyForce(int m, vect v);
        
        vect    getVel();
        vect    getAcc();
        int     getMass();
    
        virtual void    run();
};

#endif