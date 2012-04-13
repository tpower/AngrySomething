
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