/*******************************************************************************
 Filename:                  UFObird.h
 Classname:                 UFObird

 Description:               This file defines the UFObird class.
 ******************************************************************************/

#include "UFObird.h"
#include <cmath>

UFObird::UFObird(const char* file, const char* file2, int x, int y, int vx, int vy)
    :   Object(x, y, 36, 36),
        Projectile(file, x, y, vx, vy)

{
    type = 1;
    numBirds++;
    image2 = file2;
    UFOactive = false;

    activeDraw = true;
    activePhys = true;
    activeMech = true;
    activeCont = false;
}

UFObird::~UFObird()
{
    numBirds--;
}

void UFObird::run()
{
    move();

    if(pow((pow(vel.y,2) + pow(vel.x, 2)), .5) < 1)
    {
        state = -1;
    }
}

/*******************************************************************************
 Name:              handle
 Description:       handles user input
 Input:
    e               SDL_Event
 ******************************************************************************/
Object* UFObird::process()
{
    if(pos.x >= 700 and pos.y >= 25)
    {
        UFOactive = true;
        vel.x = 0;
        vel.y = -1;
        acc.x = 0;
        acc.y = -1;
        pos.x = 700;
    }

    return NULL;
}

void UFObird::draw(SDL_Surface* s)
{
    SDL_Rect temp;
    static SDL_Rect loc;
    loc = pos;

    temp.x = 600;
    temp.w = 200;
    temp.y = 10;
    temp.h = 100;

    Spaceship = SDL_LoadBMP(image2);

    if(!image2)
    {
        exit(0);
    }

    Uint32 colorkey = SDL_MapRGB( Spaceship->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey( Spaceship, SDL_SRCCOLORKEY, colorkey );

    SDL_BlitSurface(image, NULL, s, &loc);
    if(UFOactive)
        SDL_BlitSurface(Spaceship, NULL, s, &temp);
}

void UFObird::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void UFObird::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = true;
    activeCont = false;
}
