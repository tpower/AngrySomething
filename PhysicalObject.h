/*******************************************************************************
 Filename:                  PhysicalObject.h
 Classname:                 PhysicalObject
 
 Description:               This file declares the PhysicalObject class.
 ******************************************************************************/

#ifndef DrawableObject_H
#define DrawableObject_H

#include <SDL/SDL.h>

#include "Object.h"

struct vect
{
    double x, y;
};

class PhysicalObject : public Object
{
    protected:
        vect vel;
        vect acc;
    
    public:
        PhysicalObject();
        PhysicalObject(const PhysicalObject& other);
        ~PhysicalObject();
        
        PhysicalObject& operator=(const PhysicalObject& other);
    
        void            run();
};

#endif