#include "Pig.h"
#include <cmath>

int Pig::numPigs = 0;

Pig::Pig(const char* file, int x, int y, int vx, int vy)
    :   Object(x, y, 20, 20),
        DrawableObject(file, 2),
        PhysicalObject(vx, vy)
{
    health = 100;
    numPigs++;

    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}

Pig::Pig(const Pig& other)
    :   Object(other.pos.x, other.pos.y),
        DrawableObject("TestA.bmp", 2),
        PhysicalObject(other.pos.x, other.pos.y)
{
    numPigs++;
}

Pig::~Pig()
{
    numPigs--;
}

void Pig::run()
{
    move();

    if(health <= 0)
    {
        state = -1;
    }
}

void Pig::applyForce(int m, Vect v, int dir)
{
    PhysicalObject::applyForce(m, v, dir);

    if(pow((pow(v.y,2.0) + pow(v.x, 2.0)), .5) > 7)
    {
        health -= 50;
    }
}

void Pig::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void Pig::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}
