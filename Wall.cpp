#include "Wall.h"
#include <cmath>

Wall::Wall(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, 50, 50)
{
    health = 100;
}

Wall::Wall(const Wall& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        Object(other.pos.x, other.pos.y)
{

}

Wall::~Wall()
{

}

Wall& Wall::operator=(const Wall& other)
{
    if(&other != this)
    {

    }

    return *this;
}

void Wall::run()
{
    if(health <= 0)
    {
        state = -1;
    }

    move();
}

void Wall::applyForce(int m, vect v, int dir)
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

    if(v.y > 1 || v.y < -1)
    {
        health -= 101;
    }
}
