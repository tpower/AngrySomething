/*******************************************************************************
 Filename:                  MultiObject.h
 Classname:                 MultiObject
 
 Description:               This file declares the MultiObject class. This class
                            is a simple object used to test multiple inheritance
                            between different object types.
 ******************************************************************************/

#include "MultiObject.h"

MultiObject::MultiObject(const char* file, int x, int y)
    :   DrawableObject(file, x, y),
        PhysicalObject(x, y),
        Object(x, y)
{
    type = MULTI_OBJECT;
}

MultiObject::MultiObject(const MultiObject& other)
    :   DrawableObject("TestA.bmp", other.pos.x, other.pos.y),
        PhysicalObject(other.pos.x, other.pos.y),
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