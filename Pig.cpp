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

void Pig::run()
{
    if(health <= 0)
    {
        state = -1;
    }

    move();
}

void Pig::applyForce(int m, Vect v, int dir)
{
    PhysicalObject::applyForce(m, v, dir);

    if(pow((pow(v.y,2.0) + pow(v.x, 2.0)), .5) > 6)
    {
        health -= 50;
    }
}
