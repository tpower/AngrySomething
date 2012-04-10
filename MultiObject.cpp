/*******************************************************************************
 Filename:                  MultiObject.h
 Classname:                 MultiObject
 
 Description:               This file defines the MultiObject class. This class
                            is a simple object used to test multiple inheritance
                            between different object types.
 ******************************************************************************/

#include "MultiObject.h"

MultiObject::MultiObject(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        MechanicsObject(),
        Object(x, y, 18, 15)
{

}

MultiObject::MultiObject(const MultiObject& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        MechanicsObject(),
        Object(other.pos.x, other.pos.y)
{

}

MultiObject::~MultiObject()
{

}

MultiObject& MultiObject::operator=(const MultiObject& other)
{
    if(&other != this)
    {

    }

    return *this;
}
