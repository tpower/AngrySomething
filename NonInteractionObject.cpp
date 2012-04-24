/*******************************************************************************
 Filename:                  NonInteractionObject.h
 Classname:                 NonInteractionObject
 
 Description:               
 ******************************************************************************/

#include "NonInteractionObject.h"

NonInteractionObject::NonInteractionObject(const char* file, int x, int y)
    :   Object(x, y),
        DrawableObject(file, 3)

{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              draw
 Description:       Draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void NonInteractionObject::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

void NonInteractionObject::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void NonInteractionObject::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}
