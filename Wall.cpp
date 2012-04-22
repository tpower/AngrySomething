#include "Wall.h"
#include <cmath>

Wall::Wall(const char* file, int x, int y, int vx, int vy, int w, int h)
    :   Object(x, y, w, h),
        DrawableObject(file, 2),
        PhysicalObject(vx, vy)
{
    health = 100;
    type = 1;
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}

void Wall::run()
{
    move();
}

void Wall::applyForce(int m, Vect v, int dir)
{
    PhysicalObject::applyForce(m, v, dir);

    if(pow((pow(v.y,2) + pow(v.x, 2)), .5) > 30)
    {
        health -= 50;
    }
    if(pow((pow(v.y,2) + pow(v.x, 2)), .5) > 30)
    {
        health -= 101;
    }
}

/*
void Wall::draw(SDL_Surface* screen)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, screen, &loc);
}
*/

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
