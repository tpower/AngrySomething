/*******************************************************************************
 Filename:                  PhysicalObject.cpp
 Classname:                 PhysicalObject
 
 Description:               This file defines the PhysicalObject class.
 ******************************************************************************/

#include "PhysicalObject.h"

const double GRAV = .3;

/*******************************************************************************
 PhysicalObject()
 ******************************************************************************/
PhysicalObject::PhysicalObject(int vx, int vy)
{
    physical = true;
    
    vel.x = vx;
    vel.y = vy;
    
    acc.x = 0;
    acc.y = GRAV;     //gravity
    
    mass = pos.w * pos.h;
    
    collisionSide = NO_COLLISION;
    
    shape = BOX;
}

/*******************************************************************************
 MODIFIERS
 ******************************************************************************/
void PhysicalObject::setVel(Vect v)
{
    vel = v;
}

void PhysicalObject::setAcc(Vect a)
{
    acc = a;
}

void PhysicalObject::setCollisionSide(int s)
{
    collisionSide = s;
}

/*******************************************************************************
 ACCESSORS
 ******************************************************************************/
Vect PhysicalObject::getVel()
{
    return vel;
}

Vect PhysicalObject::getAcc()
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

int PhysicalObject::getShape()
{
    return shape;
}

/*******************************************************************************
 move()
 ******************************************************************************/
void PhysicalObject::move()
{
    vel.x += acc.x;
    vel.y += acc.y;
    
    //terminal velocities
    if(vel.y > 10)  vel.y = 10;
    if(vel.y < -10) vel.y = -10;
    if(vel.x > 10)  vel.x = 10;
    if(vel.x < -10) vel.x = -10;
    
    if(abs(vel.x) < .3) vel.x = 0;
    if(abs(vel.y) < 1.5 && collisionSide == BOTTOM) vel.y = 0;
    
    acc.x = 0;
    acc.y = GRAV;
    
    pos.x += vel.x;
    pos.y += vel.y;
    
    collisionSide = NO_COLLISION;
}

/*******************************************************************************
 run()
 ******************************************************************************/
void PhysicalObject::run()
{
    move();
}

/*******************************************************************************
 applyForce()
 ******************************************************************************/
void PhysicalObject::applyForce(int m, Vect v, int dir)
{
    if(dir == 0)
    {
        v.y = vel.y * .8;   //friction
        acc.x += ((m * (v.x - vel.x)) / mass) * .8;
        acc.y += (v.y - vel.y) * .8;
    }
    else if(dir == 1)
    {
        v.x = vel.x * .8;   //friction
        acc.x += (v.x - vel.x) * .8;
        acc.y += ((m * (v.y - vel.y)) / mass) * .8;
    }
    else
    {
        acc.x += ((m * (v.x - vel.x)) / mass) * .8;
        acc.y += ((m * (v.y - vel.y)) / mass) * .8;
    }
}
