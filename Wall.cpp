/*******************************************************************************
 Filename:                  Wall.h
 Classname:                 Wall
 
 Description:               The Wall class is an object that is used to create
                            structures and barriers within the game.
 ******************************************************************************/

#include <cmath>

#include "Wall.h"

Wall::Wall(const char* file, int x, int y, int vx, int vy, int w, int h)
    :   Object(x, y, w, h),
        DrawableObject(file, 2),
        PhysicalObject(vx, vy)
{
    health      = 100;
    type        = 1;
    activeDraw  = true;
    activePhys  = true;
    activeMech  = false;
    activeCont  = false;
}

Wall::~Wall()
{
    adjustScore(50);
}

void Wall::run()
{
    move();
}

void Wall::applyForce(int m, Vect v, int dir)
{
    if(dir == 0)
    {
        v.y = vel.y * .8;   //friction
        acc.x += ((m * (v.x - vel.x)) / mass) * .5;
        acc.y += (v.y - vel.y) * .2;
    }
    else if(dir == 1)
    {
        v.x = vel.x * .8;   //friction
        acc.x += (v.x - vel.x) * .5;
        acc.y += ((m * (v.y - vel.y)) / mass) * .2;
    }
    else
    {
        acc.x += ((m * (v.x - vel.x)) / mass) * .5;
        acc.y += ((m * (v.y - vel.y)) / mass) * .2;
    }

    if(pow((pow(v.y,2) + pow(v.x, 2)), .5) > 7)
    {
        health -= 50;
    }
    if(pow((pow(v.y,2) + pow(v.x, 2)), .5) > 17)
    {
        health -= 101;
    }
}

void Wall::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void Wall::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}
