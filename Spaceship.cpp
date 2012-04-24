/*******************************************************************************
 Filename:                  Spaceship.h
 Classname:                 Spaceship
 
 Description:               
 ******************************************************************************/

#include "Spaceship.h"

Spaceship::Spaceship(const char* file, int x, int y, int d, int t)
    :   Object(x, y, 100, 100),
        DrawableObject(file, 2),
        MechanicsObject()
{
    direction = d;
    startTime = SDL_GetTicks();
    time = t;
    type = 1;

    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = false;
}

Object* Spaceship::process()
{
    if((SDL_GetTicks() - startTime) > time + 5000)
    {
        state = -1;
    }
    else if((SDL_GetTicks() - startTime) > time)
    {
        //vect v;
        switch(direction)
        {
            case UL:
                pos.x += -7;
                pos.y += -7;
                break;
            case UR:
                pos.x += 7;
                pos.y += -7;
                break;
            case DL:
                pos.x += -7;
                pos.y += 7;
                break;
            case DR:
                pos.x += 7;
                pos.y += 7;
                break;
        }
    }
    return NULL;
}

void Spaceship::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    Uint32 colorkey = SDL_MapRGB( image->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey( image, SDL_SRCCOLORKEY, colorkey );

    SDL_BlitSurface(image, NULL, s, &loc);
}

void Spaceship::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void Spaceship::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = false;
}
