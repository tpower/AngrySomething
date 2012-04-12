#include "Wall.h"
#include <cmath>

Wall::Wall(const char* file, int x, int y, int vx, int vy, int w, int h)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, w, h)
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

void Wall::applyForce(int m, Vect v, int dir)
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

    if(pow((pow(v.y,2) + pow(v.x, 2)), .5) > 7)
    {
        health -= 50;
    }
    if(pow((pow(v.y,2) + pow(v.x, 2)), .5) > 8)
    {
        health -= 101;
    }
}
