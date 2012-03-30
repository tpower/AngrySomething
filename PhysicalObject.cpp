/*******************************************************************************
 Filename:                  PhysicalObject.cpp
 Classname:                 PhysicalObject
 
 Description:               This file defines the PhysicalObject class.
 ******************************************************************************/

#include <iostream>

#include "PhysicalObject.h"

using namespace std;

/*******************************************************************************
 Name:              PhysicalObject
 Description:       Primary constructor
 ******************************************************************************/
PhysicalObject::PhysicalObject() : Object()
{
    type = PHYSICAL_OBJECT;
    
    vel.x = 1;
    vel.y = 1;
    
    acc.x = 0;
    acc.y = 0;
}

/*******************************************************************************
 Name:              PhysicalObject
 Description:       Copy constructor
 
 Input:
 other           PhysicalObject& to be copied
 ******************************************************************************/
PhysicalObject::PhysicalObject(const PhysicalObject& other)
{
    
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
        
    }
    
    return *this;
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