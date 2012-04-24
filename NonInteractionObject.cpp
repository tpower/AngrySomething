/*******************************************************************************
 Filename:                  NonInteractionObject.h
 Classname:                 NonInteractionObject
 
 Description:               
 ******************************************************************************/

#include "NonInteractionObject.h"

/*******************************************************************************
 Name:              NonInterationObject
 Description:       Primary constructor
 
 Input:
    file            char* filepath for image file
    x               int horizontal position
    y               int vertical position
 ******************************************************************************/
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
 Description:       Overrides DrawableObject::draw()

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void NonInteractionObject::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the NonInteractionObject
 ******************************************************************************/
void NonInteractionObject::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the NonInteractionObject if it is paused
 ******************************************************************************/
void NonInteractionObject::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}
