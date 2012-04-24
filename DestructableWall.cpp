/*******************************************************************************
 Filename:                  DestructableWall.h
 Classname:                 DestructableWall
 
 Description:               The DestructableWall class is a subclass of Wall
                            that can be destroyed.
 ******************************************************************************/

#include "DestructableWall.h"

DestructableWall::DestructableWall(const char* file, int x, int y, int vx,
                                   int vy, int w, int h)
    :   Object(x, y, w, h),
        Wall(file, x, y, vx, vy, w, h)
{
    health = 100;
    type = 1;
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}

void DestructableWall::run()
{
    move();

    if(health <= 0)
    {
        state = -1;
    }
}
