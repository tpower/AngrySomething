/*******************************************************************************
 Filename:                  PauseButton.h
 Classname:                 PauseButton
 ******************************************************************************/

#include "PauseButton.h"
#include "GraphicsEngine.h"
#include "Room.h"

PauseButton::PauseButton(const char* file, int x, int y, int w, int h)
    :   Object(x, y, w, h),
        DrawableObject(file, 3)
{
    type = 2;
    Value = 0;
    clicked = false;
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = true;
}

/*******************************************************************************
 Name:              handle
 Description:       handles user input
 Input:
    e               SDL_Event
 ******************************************************************************/
void PauseButton::handle(SDL_Event e)
{
    int mouseX, mouseY;
    bool MenuOpen = false;

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
                SDL_Event event;
                Room temp;
                GraphicsEngine graph;

                MenuOpen = true;
                temp.add(new ClickableObject("Resume.bmp", 30, 30, 25, 25, 1));
                temp.add(new ClickableObject("Reset.bmp", 80, 30, 25, 25, 2));
                temp.add(new ClickableObject("Exit.bmp", 120, 30, 25, 25, 3));
                temp.add(new ClickableObject("Unpause.bmp", 160, 15, 25, 25, 4));
                while(MenuOpen)
                {
                    graph.run(temp);
                    if(SDL_PollEvent(&event))
                    {
                        if( event.type == SDL_QUIT )
                        {
                            exit(0);
                        }
                        for(int i = 0; i < 4; i++)
                        {
                            dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->handle(event);
                            if(dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->check() == 4)
                            {   //Continue Running
                                MenuOpen = false;
                                Value = 0;
                                clicked = true;
                            }
                            dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->handle(event);
                            if(dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->check() == 1)
                            {   //Continue Running
                                MenuOpen = false;
                                Value = 0;
                                clicked = true;
                            }
                            dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->handle(event);
                            if(dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->check() == 2)
                            {   //Restart the level
                                MenuOpen = false;
                                Value = -5;
                                clicked = true;
                            }
                            dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->handle(event);
                            if(dynamic_cast<ControllableObject*>(temp.getObjectAt(i))->check() == 3)
                            {   //Exit to title screen
                                MenuOpen = false;
                                Value = -3;
                                clicked = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

/*******************************************************************************
 Name:              check
 Description:       This method checks to see if the room needs to change
 
 Output:
    returns         int
 ******************************************************************************/
int PauseButton::check()
{
    int temp = 0;
    if(clicked)
    {
        temp = Value;
        clicked = false;
        Value = 0;
    }

    return temp;
}

/*******************************************************************************
 Name:              draw
 Description:       Draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void PauseButton::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the PauseButton
 ******************************************************************************/
void PauseButton::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = true;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the PauseButton if it is paused
 ******************************************************************************/
void PauseButton::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = true;
}
