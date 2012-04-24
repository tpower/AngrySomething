/*******************************************************************************
 Filename:                  ClickableObject.h
 Classname:                 ClickableObject
 ******************************************************************************/

#include "ClickableObject.h"

/*******************************************************************************
 Name:              ClickableObject
 Description:       Primary constructor
 
 Input:
    file            char* filepath to an image file
    x               int horizontal position
    y               int vertical position
    w               int width
    h               int height
    v               int value of ClickableObject
 ******************************************************************************/
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
 Description:       This method overrides ControllableObject::handle()
 
 Input:
    e               SDL_Event to be handled
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

/*******************************************************************************
 Name:              check
 Description:       This method returns the value of the ClickableObject when it
                    is clicked
 
 Output:
    returns         int value of ClickableObject
 ******************************************************************************/
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
 Description:       This method draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void ClickableObject::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the ClickableObject
 ******************************************************************************/
void ClickableObject::pause()
{
    activeDraw = false;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the ClickableObject if it is paused
 ******************************************************************************/
void ClickableObject::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = true;
}
