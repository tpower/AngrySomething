/*******************************************************************************
 Filename:                  Slingshot.cpp
 Classname:                 Slingshot

 Description:               This file implements the Slingshot class. A slingshot is
                            simply drawable, and exists only for the visual
                            element of the sling.
 ******************************************************************************/

#include "Slingshot.h"

/*******************************************************************************
 Name:              Slingshot
 Description:       constructor
******************************************************************************/
Slingshot::Slingshot(const char* file, int x, int y)
    :   DrawableObject(file),
        Object(x, y, 180, 150)
{

}
