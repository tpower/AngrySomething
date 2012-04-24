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

/*******************************************************************************
    Name:                   Destructor
    Description:            Destructs the Wall and adds 50 points the static
                            score counter.
    Input:
            None

    Output:
            None

 ******************************************************************************/
Wall::~Wall()
{
    adjustScore(50);
}

/*******************************************************************************
    Name:                   Run()
    Description:            Calls the move method of the PhysicalObject class
                            which it inherits from.
    Input:
            None

    Output:
            None

 ******************************************************************************/
void Wall::run()
{
    move();
}

/*******************************************************************************
    Name:                   applyForce
    Description:            Overridden applyForce method. Applies a vector from
                            a collision to this object and adjusts it's health
                            if that vector force was great enough to cause
                            damage to it.
    Input:
            None

    Output:
            None

 ******************************************************************************/
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

/*******************************************************************************
    Name:                   unpause
    Description:            Turns on all of the components of the Object that
                            get handled by engines for this specific Object.
    Input:
            None

    Output:
            None

 ******************************************************************************/
void Wall::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}
