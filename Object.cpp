/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object

 Description:               This file defines the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 ******************************************************************************/
#include "Object.h"

Object::Object(int x, int y) : Base(OBJECT)
{
    position.x = x;
    position.y = y;
}


