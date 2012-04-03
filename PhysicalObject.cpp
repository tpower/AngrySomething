/*******************************************************************************
 Filename:                  PhysicalObject.cpp
 Classname:                 PhysicalObject
 
 Description:               This file defines the PhysicalObject class.
 ******************************************************************************/

#include <cstdlib>

#include "PhysicalObject.h"

/*******************************************************************************
 Name:              PhysicalObject
 Description:       Primary constructor
 ******************************************************************************/
PhysicalObject::PhysicalObject(int x, int y) : Object(x, y)
{
    type = PHYSICAL_OBJECT;
    
    vel.x = rand() % 5;
    vel.y = rand() % 5;
    
    acc.x = 0;
    acc.y = 0;
}

/*******************************************************************************
 Name:              PhysicalObject
 Description:       Copy constructor
 
 Input:
 other           PhysicalObject& to be copied
 ******************************************************************************/
PhysicalObject::PhysicalObject(const PhysicalObject& other) : Object(other.pos.x, other.pos.y)
{
    vel = other.vel;
    acc = other.acc;
}

/*******************************************************************************
 Name:              ~PhysicalObject
 Description:       Destructor
 ******************************************************************************/
PhysicalObject::~PhysicalObject()
{
    
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator
 
 Input:
 other           PhysicalObject& to be copied
 ******************************************************************************/
PhysicalObject& PhysicalObject::operator=(const PhysicalObject& other)
{
    if(&other != this)
    {
        vel = other.vel;
        acc = other.acc;
    }
    
    return *this;
}

/*******************************************************************************
 MODIFIERS
 Name:              setVel, setAcc
 ******************************************************************************/
void PhysicalObject::setVel(vect v)
{
    vel = v;
}

void PhysicalObject::setAcc(vect a)
{
    acc = a;
}

/*******************************************************************************
 MODIFIERS
 Name:              setVel, setAcc
 ******************************************************************************/
vect PhysicalObject::getVel()
{
    return vel;
}

vect PhysicalObject::getAcc()
{
    return acc;
}

/*******************************************************************************
 Name:              run
 Description:       ????????
 ******************************************************************************/
void PhysicalObject::run()
{
    vel.x += acc.x;
    vel.y += acc.y;
    
    pos.x += vel.x;
    pos.y += vel.y;
}