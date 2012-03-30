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
Object::Object(int x, int y)
{
    type = OBJECT;
    
    pos.x = x;
    pos.y = y;
    pos.w = 60;
    pos.h = 60;
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other)
{
    type    = other.type;
    pos     = other.pos;
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
        type    = other.type;
        pos     = other.pos;
    }
    
    return *this;
}

/*******************************************************************************
 MUTATORS
 Name:              setType, setPos
 ******************************************************************************/
void Object::setType(ObjType t)
{
    type = t;
}

void Object::setPos(SDL_Rect p)
{
    pos = p;
}

/*******************************************************************************
 ACCESSORS
 Name:              getType, getPos
 ******************************************************************************/
ObjType Object::getType()
{
    return type;
}

SDL_Rect Object::getPos()
{
    return pos;
}