/*******************************************************************************
 Filename:                  PhysicalObject.h
 Classname:                 PhysicalObject
 
 Description:               The PhysicalObject class is a subclass of Object
                            that can move around the screen and collide with
                            other PhysicalObjects.
 ******************************************************************************/

#include "PhysicalObject.h"

const double GRAV       = .1;
const double TERM_VEL   = 20;

/*******************************************************************************
 Name:              PhysicalObject
 Description:       Primary constructor
 
 Input:
    vx              int horizontal velocity
    vy              int vertical velocity
 ******************************************************************************/
PhysicalObject::PhysicalObject(int vx, int vy)
{
    physical = true;

    vel.x = vx;
    vel.y = vy;

    acc.x = 0;
    acc.y = GRAV;

    mass = 1600;

    collisionSide = NO_COLLISION;

    shape = BOX;
}

/*******************************************************************************
 MODIFIERS
 Name:              setVel, setAcc, setCollisionSide
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
    if(s == BOTTOM)
       collisionSide = s;
}

/*******************************************************************************
 ACCESSORS
 Name:              getVel, getAcc, getMass, getCollisionSide, getShape
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
 Name:              move
 Description:       This method changes the PhysicalObject's position on the
                    screen based on velocity and acceleration
 ******************************************************************************/
void PhysicalObject::move()
{
    vel.x += acc.x;
    vel.y += acc.y;

    //terminal velocities
    if(vel.y > TERM_VEL)  vel.y = TERM_VEL;
    if(vel.y < -TERM_VEL) vel.y = -TERM_VEL;
    if(vel.x > TERM_VEL)  vel.x = TERM_VEL;
    if(vel.x < -TERM_VEL) vel.x = -TERM_VEL;

    if(abs(vel.x) < .3) vel.x = 0;
    if(abs(vel.y) < 1.5 && collisionSide == BOTTOM) vel.y = 0;

    acc.x = 0;
    acc.y = GRAV;

    pos.x += round(vel.x);
    pos.y += round(vel.y);

    collisionSide = NO_COLLISION;
}

/*******************************************************************************
 Name:              run
 Description:       This method runs the PhysicalObject
 ******************************************************************************/
void PhysicalObject::run()
{
    move();
}

/*******************************************************************************
 Name:              applyForce
 Description:       This method handles a force given by a collision
 
 Input:
    m               int mass of colliding object
    v               Vect of colliding objects velocity
    dir             int direction of collision
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
