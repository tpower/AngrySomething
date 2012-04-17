#include "PauseButton.h"
#include "GraphicsEngine.h"
#include "Room.h"

PauseButton::PauseButton(const char* file, int x, int y, int w, int h)
    :   Object(x, y, w, h),
        DrawableObject(file)

{
    type = 2;
}

PauseButton::~PauseButton()
{

}

/*******************************************************************************
 Name:              handle
 Description:       handles user input
 Input:
    e               SDL_Event
 ******************************************************************************/
int PauseButton::handleU(SDL_Event e)
{
    int mouseX, mouseY;
    bool MenuOpen = false;
    int state;

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
                            if(dynamic_cast<MechanicsObject*>(temp.getObjectAt(i))->handleU(event) == 4)
                            {
                                MenuOpen = false;
                                state = 0;
                            }
                            if(dynamic_cast<MechanicsObject*>(temp.getObjectAt(i))->handleU(event) == 1)
                            {
                                MenuOpen = false;
                                state = 0;
                            }
                            if(dynamic_cast<MechanicsObject*>(temp.getObjectAt(i))->handleU(event) == 2)
                            {
                                MenuOpen = false;
                                state = -5;
                            }
                            if(dynamic_cast<MechanicsObject*>(temp.getObjectAt(i))->handleU(event) == 3)
                            {
                                MenuOpen = false;
                                state = -4;
                            }
                        }
                    }
                }
            }
        }
    }
    return state;
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
