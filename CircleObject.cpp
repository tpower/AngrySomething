
#include "CircleObject.h"

CircleObject::CircleObject(int vx, int vy) : PhysicalObject(vx, vy)
{
    circ    = Circle(pos);
    shape   = CIRCLE;
}

Circle CircleObject::getCircle()
{
    return circ;
}

void CircleObject::run()
{
    move();

    circ.cent.x = pos.x + circ.rad;
    circ.cent.y = pos.y + circ.rad;
}

/*******************************************************************************
 applyForce()
 ******************************************************************************/
void CircleObject::applyForce(int m, Vect v)
{
    acc.x += ((m * (v.x)) / mass) * .8;
    acc.y += ((m * (v.y)) / mass) * .8;
}
