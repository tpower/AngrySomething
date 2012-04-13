#include "Pig.h"
#include <cmath>

int Pig::numPigs = 0;

Pig::Pig(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, 40, 40)
{
    health = 100;
    numPigs++;
}

Pig::Pig(const Pig& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        Object(other.pos.x, other.pos.y)
{
    numPigs++;
}

Pig::~Pig()
{
    numPigs--;
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

    if(pow((pow(v.y,2.0) + pow(v.x, 2.0)), .5) > 8)
    {
        health -= 50;
    }
}
