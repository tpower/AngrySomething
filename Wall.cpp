#include "Wall.h"
#include <cmath>

Wall::Wall(const char* file, int x, int y, int vx, int vy, int w, int h)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, w, h)
{
    health = 100;
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
    if(pow((pow(v.y,2) + pow(v.x, 2)), .5) < .85)
    {
        PhysicalObject::applyForce(m, v, dir);
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
