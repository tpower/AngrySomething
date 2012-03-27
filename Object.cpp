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
    position.w = 60;
    position.h = 60;
    
    vel.x = vel.y = 1;
}

SDL_Rect Object::getPosition()
{
    return position;
}

vect Object::getVel()
{
    return vel;
}

void Object::setPosition(SDL_Rect p)
{
    position = p;
}

void Object::setVel(vect v)
{
    vel = v;
}

void Object::run()
{
    position.x += vel.x;
    position.y += vel.y;
}