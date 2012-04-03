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
    pos.h = w;
    
    drawable = physical = mechanical = false;
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other)
{
    pos = other.pos;
}

/*******************************************************************************
 Name:              ~Object
 Description:       Destructor for Object class
 ******************************************************************************/
Object::~Object()
{
    
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Object class

 Input:
    other           const Object&
 ******************************************************************************/
Object Object::operator=(const Object& other)
{
    if(&other != this)
    {
        pos = other.pos;
    }
    
    return *this;
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
