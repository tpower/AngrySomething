#include "Pig.h"
#include <cmath>

Pig::Pig(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, 50, 50)
{
    health = 100;
}

Pig::Pig(const Pig& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        Object(other.pos.x, other.pos.y)
{

}

Pig::~Pig()
{

}

Pig& Pig::operator=(const Pig& other)
{
    if(&other != this)
    {

    }

    return *this;
}

void Pig::run()
{
    if(health <= 0)
    {
        state = -1;
    }

    move();
}

void Pig::applyForce(int m, vect v, int dir)
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
        health -= 50;
    }
}
