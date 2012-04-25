/*******************************************************************************
 Filename:                  MenuItem.h
 Classname:                 MenuItem
 ******************************************************************************/

#include "MenuItem.h"

MenuItem::MenuItem(const char* file, int x, int y, int w, int h, int v)
    :   Object(x, y, w, h),
        DrawableObject(file, 3)
{
    value = v;
    clicked = false;
    activeDraw = false;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              handle
 Description:       This method overrides ControllableObject::handle()
 
 Input:
    e               SDL_Event to be handled
 ******************************************************************************/
void MenuItem::handle(SDL_Event e)
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
            }
        }
    }
}

/*******************************************************************************
 Name:              check
 Description:       This method returns the value of the MenuItem when it is
                    clicked
 
 Output:
    returns         int value of ClickableObject
 ******************************************************************************/
int MenuItem::check()
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
void MenuItem::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the MenuItem
 ******************************************************************************/
void MenuItem::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = true;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the MenuItem if it is paused
 ******************************************************************************/
void MenuItem::unpause()
{
    activeDraw = false;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}
