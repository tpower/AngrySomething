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
 Name:              setPos
 ******************************************************************************/
void Object::setPos(SDL_Rect p)
{
    pos = p;
}

/*******************************************************************************
 ACCESSORS
 Name:              getPos
 ******************************************************************************/
SDL_Rect Object::getPos()
{
    return pos;
}

/*******************************************************************************
 Name:              run
 Description:       this method runs the object
 ******************************************************************************/
void Object::run()
{
    
}