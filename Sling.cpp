/*******************************************************************************
 Filename:                  Sling.cpp
 Classname:                 Sling

 Description:               This file implements the Sling class. This class
                            is an object capable of taking user input to direct
                            the slings angle, and spawn a bird at the proper
                            velocity and position.
 ******************************************************************************/

#include "Sling.h"

/*******************************************************************************
 Name:              Sling
 Description:       Constructor

 Input:
    file            The image filename
    x, y            The x and y coordinates of the object
 ******************************************************************************/
Sling::Sling(const char* file, int x, int y, string ammo)
    :   Object(x, y, 180, 150),
        DrawableObject(file),
        MechanicsObject()

{
    Slingshot.x = x - 25;
    Slingshot.y = y;

    /******************
    bounds.x = x - 75;
    bounds.w = x + 75;
    bounds.y = y - 75;
    bounds.h = y + 75;
    ******************/
    radius = 125;

    projectiles = ammo;
    projectileCount = projectiles.length();
}

/*******************************************************************************
 Name:              ~Sling
 Description:       destructor

 ******************************************************************************/
Sling::~Sling()
{

}

/*******************************************************************************
 Name:              checkBounds
 Description:       Checks to see if the mouse is currently near enough
                    to the Sling to interact with it
 Input:
    e               SDL_Event
 ******************************************************************************/
bool Sling::checkBounds(SDL_Event e)
{
    bool inBounds = false;

    //if(e.motion.x > bounds.x && e.motion.x < bounds.x + bounds.w)
    if(sqrt(pow(e.motion.x-Slingshot.x,2) + pow(e.motion.y-Slingshot.y,2)) < radius)
    {
            inBounds = true;
    }
    return inBounds;
}

/*******************************************************************************
 Name:              createMonkey
 Description:       Creates and returns a Monkey with correct position, velocity,
                    and accelleration
 Input:
    xVel, yVel      The x and y velocities of the object
 ******************************************************************************/
MultiObject* Sling::createMonkey(char monkeyType, int xPos, int yPos, int xVel, int yVel)
{
    MultiObject* p;
    switch (monkeyType)
    {
        case 'N':       p = new MultiObject("TestA.bmp", xPos, yPos, xVel, yVel);
                        break;

    }
    return p;
}


/*******************************************************************************
 Name:              handle
 Description:       handles user input
 Input:
    e               SDL_Event
 ******************************************************************************/
Object* Sling::handle(SDL_Event e)
{
    MultiObject* monk = NULL;
    static bool grabbed = false;;

    if(checkBounds(e))
    {
        int static centerX = pos.x;
        int static centerY = pos.y;

        if(e.type == SDL_MOUSEMOTION && grabbed)
        {
            pos.x = e.motion.x;
            pos.y = e.motion.y;
        }

        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                pos.x = e.button.x;
                pos.y = e.button.y;

                grabbed = true;
            }
        }

        if(e.type == SDL_MOUSEBUTTONUP)
        {
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                if(projectileCount > 0)
                {
                    monk = createMonkey(projectiles[projectileCount-1], pos.x, pos.y, (centerX - pos.x)*.2, (centerY - pos.y)*.2);
                    projectileCount--;
                }
                pos.x = centerX;
                pos.y = centerY;

                grabbed = false;
            }
        }
    }
    return monk;
}

/*******************************************************************************
 Name:              draw
 Description:       Draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void Sling::draw(SDL_Surface* s)
{
    SDL_Surface* SlingshotIMG;
    SlingshotIMG = SDL_LoadBMP("Slingshot.bmp");
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(SlingshotIMG, NULL, s, &Slingshot);
    SDL_BlitSurface(image, NULL, s, &loc);
}
