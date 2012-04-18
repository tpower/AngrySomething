/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object

 Description:               This file defines the Object class.
 ******************************************************************************/

#include "Object.h"

/*******************************************************************************
 Name:              Object
 Description:       Default constructor for Object class
 ******************************************************************************/
Object::Object(int x, int y, int w, int h)
{
    pos.x = x;
    pos.y = y;
    pos.w = w;
    pos.h = h;

    drawable = physical = mechanical = false;

    state = 0;
    type = 0;
}

Object::~Object()
{
    
}

/*******************************************************************************
 MUTATORS
 Name:              setType, setPos
 ******************************************************************************/
void Object::setPos(SDL_Rect p)
{
    pos = p;
}

/*******************************************************************************
 ACCESSORS
 Name:              getType, getPos
 ******************************************************************************/
SDL_Rect Object::getPos()
{
    return pos;
}

int Object::getState()
{
    return state;
}

int Object::getType()
{
    return type;
}

bool Object::isDrawable()
{
    return drawable;
}

bool Object::isPhysical()
{
    return physical;
}

bool Object::isMechanical()
{
    return mechanical;
}

/*******************************************************************************
 Name:              run
 Description:       ??????
 ******************************************************************************/
void Object::run()
{

}
