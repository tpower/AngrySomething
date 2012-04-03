/*******************************************************************************
 Filename:                  MultiObject.h
 Classname:                 MultiObject
 
 Description:               This file declares the MultiObject class. This class
                            is a simple object used to test multiple inheritance
                            between different object types.
 ******************************************************************************/

#ifndef AngrySomething_MultiObject_h
#define AngrySomething_MultiObject_h

#include "DrawableObject.h"
#include "PhysicalObject.h"

class MultiObject : public DrawableObject, public PhysicalObject
{
    public:
        MultiObject(const char* file, int x, int y);
        MultiObject(const MultiObject& other);
        ~MultiObject();
        
        MultiObject&    operator=(const MultiObject& other);
};

#endif
