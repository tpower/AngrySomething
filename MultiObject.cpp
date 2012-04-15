/*******************************************************************************
 Filename:                  MultiObject.h
 Classname:                 MultiObject

 Description:               This file declares the MultiObject class. This class
                            is a simple object used to test multiple inheritance
                            between different object types.
 ******************************************************************************/

#include "MultiObject.h"

MultiObject::MultiObject(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        MechanicsObject(),
        Object(x, y, 50, 50)
{

}
