/*******************************************************************************
 Filename:                  Spaceship.h
 Classname:                 Spaceship
 
 Description:               This class is a spaceship used in the initial
                            cut-scene
 ******************************************************************************/

#include "Spaceship.h"

/*******************************************************************************
 Name:              Spaceship
 Description:       Primary constructor
 
 Input:
    file            char* filepath for image file
    x               int horizontal position
    y               int vertical position
    d               int direction
    t               int start time
 ******************************************************************************/
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

/*******************************************************************************
 Name:              process
 Description:       This method overrides MechanicsObject::process()
 
 Output:
    returns         Object* to be added to the room
 ******************************************************************************/
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

/*******************************************************************************
 Name:              draw
 Description:       This method overrides DrawableObject::draw()
 
 Input:
    s               SDL_Surface* to be drawn to
 ******************************************************************************/
void Spaceship::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    Uint32 colorkey = SDL_MapRGB( image->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey( image, SDL_SRCCOLORKEY, colorkey );

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the Spaceship
 ******************************************************************************/
void Spaceship::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the Spaceship if it is paused
 ******************************************************************************/
void Spaceship::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = false;
}
