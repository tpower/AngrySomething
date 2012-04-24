/*******************************************************************************
 Filename:                  CircleObject.h
 Classname:                 CircleObject
 
 Description:               The CircleObject class is a subclass of
                            PhysicalObject that adds circular collision handling
                            to a PhysicalObject.
 ******************************************************************************/

#include "CircleObject.h"

/*******************************************************************************
 Name:              CircleObject
 Description:       Primary constructor
 
 Input:
    vx              int horizontal velocity
    vy              int vertical velocity
 ******************************************************************************/
CircleObject::CircleObject(int vx, int vy) : PhysicalObject(vx, vy)
{
    circ    = Circle(pos);
    shape   = CIRCLE;
}

/*******************************************************************************
 ACCESSORS
 Name:              getCircle
 ******************************************************************************/
Circle CircleObject::getCircle()
{
    return circ;
}

/*******************************************************************************
 Name:              run
 Description:       This method overrides PhysicalObject::run() and moves the
                    circle to the object's new position
 ******************************************************************************/
void CircleObject::run()
{
    move();

    circ.cent.x = pos.x + circ.rad;
    circ.cent.y = pos.y + circ.rad;
}

/*******************************************************************************
 Name:              applyForce
 Description:       This method applies a force to an object to change it's
                    acceleration
 ******************************************************************************/
void CircleObject::applyForce(int m, Vect v)
{
    acc.x += ((m * (v.x)) / mass) * .8;
    acc.y += ((m * (v.y)) / mass) * .8;
}
