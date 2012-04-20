#include "Wall.h"
#include <cmath>

Wall::Wall(const char* file, int x, int y, int vx, int vy, int w, int h)
    :   DrawableObject(file, 2),
        PhysicalObject(vx, vy),
        Object(x, y, w, h)
{
    health = 100;
    type = 1;
}

void Wall::run()
{
    move();

    if(health <= 0)
    {
        state = -1;
    }
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

void Wall::draw(SDL_Surface* screen)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, screen, &loc);
}
