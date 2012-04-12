/*******************************************************************************
 Filename:                  PhysicalObject.cpp
 Classname:                 PhysicalObject
 
 Description:               This file defines the PhysicalObject class.
 ******************************************************************************/

#include "PhysicalObject.h"

const double GRAV = .3;

/*******************************************************************************
 Name:              PhysicalObject
 Description:       Primary constructor
 ******************************************************************************/
PhysicalObject::PhysicalObject(int x, int y)
{
    physical = true;
    
    vel.x = x;
    vel.y = y;
    
    acc.x = 0;
    acc.y = GRAV;     //gravity
    
    mass = pos.w * pos.h;
    
    collisionSide = NO_COLLISION;
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

void PhysicalObject::applyForce(int m, vect v, int dir)
{
    if(dir == 0)
    {
        acc.x += ((m * (v.x - vel.x)) / mass) * .8;
    }
    else if(dir == 1)
    {
        acc.y += ((m * (v.y - vel.y)) / mass) * .8;
    }
    else
    {
        acc.x += ((m * (v.x - vel.x)) / mass) * .8;
        acc.y += ((m * (v.y - vel.y)) / mass) * .8;
    }
}

void PhysicalObject::setCollisionSide(int s)
{
    collisionSide = s;
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

int PhysicalObject::getMass()
{
    return mass;
}

int PhysicalObject::getCollisionSide()
{
    return collisionSide;
}

/*******************************************************************************
 Name:              run
 Description:       ????????
 ******************************************************************************/
void PhysicalObject::run()
{
    move();
}

void PhysicalObject::move()
{
    vel.x += acc.x;
    vel.y += acc.y;
    
    if(vel.y > 10)  vel.y = 10;         //terminal velocity
    if(vel.y < -10) vel.y = -10;        //terminal velocity
    if(vel.x > 10)  vel.x = 10;         //terminal velocity
    if(vel.x < -10) vel.x = -10;        //terminal velocity
    
    if(abs(vel.x) < .3) vel.x = 0;
    if(abs(vel.y) < 1.5 && collisionSide == BOTTOM) vel.y = 0;
    
    acc.x = 0;
    acc.y = GRAV;
    
    pos.x += vel.x;
    pos.y += vel.y;
    
    collisionSide = NO_COLLISION;
}