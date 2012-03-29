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
    position.x = x;
    position.y = y;
    position.w = 60;
    position.h = 60;
}

SDL_Rect Object::getPosition()
{
    return position;
}

void Object::setPosition(SDL_Rect p)
{
    position = p;
}

void Object::run()
{
    
}