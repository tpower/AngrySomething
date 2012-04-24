/*******************************************************************************
 Filename:                  DestructableWall.h
 Classname:                 DestructableWall
 
 Description:               The DestructableWall class is a subclass of Wall
                            that can be destroyed.
 ******************************************************************************/

#include "DestructableWall.h"

/*******************************************************************************
 Name:              DestructableWall
 Description:       Primary constructor
 
 Input:
    file            char* filepath for image file
    x               int horizontal position
    y               int vertical position
    vx              int horizontal velocity
    vy              int vertical velocity
    w               int width
    h               int height
 ******************************************************************************/
DestructableWall::DestructableWall(const char* file, int x, int y, int vx, int vy, int w, int h)
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

/*******************************************************************************
 Name:              run
 Description:       This method overrides PhysicalObject::run() and handles
                    changing state if health is 0
 ******************************************************************************/
void DestructableWall::run()
{
    move();

    if(health <= 0)
    {
        state = -1;
    }
}
