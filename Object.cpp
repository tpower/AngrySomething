/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object

 Description:               This file defines the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 ******************************************************************************/

#include "Object.h"

Object::Object(int x, int y)
{
    pos.x = x;
    pos.y = y;
    pos.w = 60;
    pos.h = 60;
}

SDL_Rect Object::getPos()
{
    return pos;
}

void Object::setPos(SDL_Rect p)
{
    pos = p;
}

void Object::run()
{
    
}