/*******************************************************************************
 Filename:                  Slingshot.h
 Classname:                 Slingshot

 Description:               This file declares the Slingshot class. A slingshot is
                            simply drawable, and exists only for the visual
                            element of the sling.
 ******************************************************************************/

#ifndef SLINGSHOT_H
#define SLINGSHOT_H

#include "DrawableObject.h"
//#include "PhysicalObject.h"
//#include "MechanicsObject.h"

class Slingshot : public DrawableObject
{
    public:
        Slingshot(const char* file, int x, int y);
        ~Slingshot();
};


#endif // SLINGSHOT_H
