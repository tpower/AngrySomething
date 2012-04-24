/*******************************************************************************
 Filename:                  ClickableObject.h
 Classname:                 ClickableObject
 
 Description:               
 ******************************************************************************/

#include "ClickableObject.h"

ClickableObject::ClickableObject(const char* file, int x, int y, int w, int h, int v)
    :   Object(x, y, w, h),
        DrawableObject(file, 3),
        AudibleObject("noise.wav")
{
    value = v;
    clicked = false;
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = true;
}

/*******************************************************************************
 Name:              handle
 Description:       handles user input
 Input:
    e               SDL_Event
 ******************************************************************************/
void ClickableObject::handle(SDL_Event e)
{
    int mouseX, mouseY;

    if(e.type == SDL_MOUSEMOTION)
    {
        mouseX = e.motion.x;
        mouseY = e.motion.y;
    }

    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            mouseX = e.button.x;
            mouseY = e.button.y;

            if(mouseX >= pos.x && mouseX <= pos.x + pos.w && mouseY >= pos.y && mouseY <= pos.y + pos.h)
            {
                clicked = true;
                shouldBeNoisy();
            }
        }
    }
}

int ClickableObject::check()
{
    int temp = 0;
    if(clicked)
    {
        temp = value;
        clicked = false;
    }

    return temp;
}

/*******************************************************************************
 Name:              draw
 Description:       Draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void ClickableObject::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

void ClickableObject::pause()
{
    activeDraw = false;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void ClickableObject::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = true;
}
