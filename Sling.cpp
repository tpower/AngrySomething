/*******************************************************************************
 Filename:                  Sling.cpp
 Classname:                 Sling

 Description:               This file implements the Sling class. This class
                            is an object capable of taking user input to direct
                            the slings angle, and spawn a bird at the proper
                            velocity and position.
 ******************************************************************************/

#include <cmath>

#include "Sling.h"

/*******************************************************************************
 Name:              Sling
 Description:       Constructor

 Input:
    file            The image filename
    x, y            The x and y coordinates of the object
 ******************************************************************************/

int Sling::projectileCount = 0;

Sling::Sling(const char* file, int x, int y, string ammo)
    :   Object(x, y, 180, 150),
        DrawableObject(file, 2),
        MechanicsObject()
{
    grabbed = false;

    launcherImg = SDL_LoadBMP("Slingshot.bmp");

    Slingshot.x = x - 25;
    Slingshot.y = y;

    radius = 75;

    monk = NULL;

    projectiles = ammo;
    projectileCount = (int)projectiles.length();

    type = 1;

    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = true;
}

/*******************************************************************************
 Name:              ~Sling
 Description:       destructor

 ******************************************************************************/
Sling::~Sling()
{
    SDL_FreeSurface(launcherImg);
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
    if(sqrt(pow(e.motion.x - Slingshot.x, 2.0) + pow(e.motion.y - Slingshot.y, 2.0)) < radius)
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
Projectile* Sling::createMonkey(char type, int xPos, int yPos, int xVel, int yVel)
{
    Projectile* p;

    switch (type)
    {
        case 'N':
            p = new Projectile("Monkey.bmp", xPos, yPos, xVel, yVel);
            break;
        case 'U':
            p = new UFObird("AngryBird.bmp", "UFO.bmp", xPos, yPos, xVel, yVel);
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
void Sling::handle(SDL_Event e)
{
    monk = NULL;
    static bool grabbed = false;

    int static centerX = pos.x;
    int static centerY = pos.y;

    if(checkBounds(e))
    {
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
                    monk = createMonkey(projectiles[projectileCount - 1], pos.x, pos.y, (centerX - pos.x)*.2, (centerY - pos.y)*.2);
                    projectileCount--;
                }

                pos.x = centerX;
                pos.y = centerY;

                grabbed = false;
            }
        }
    }
    else
    {
        if(e.type == SDL_MOUSEMOTION && grabbed)
        {
            int tx = e.motion.x - centerX;
            int ty = e.motion.y - centerY;
            int c = sqrt(pow(tx, 2.0) + pow(ty, 2.0));

            int xDist = tx * radius / c;
            int yDist = ty * radius / c;

            pos.x = centerX + xDist;
            pos.y = centerY + yDist;
        }

        if(e.type == SDL_MOUSEBUTTONUP && grabbed)
        {
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                if(projectileCount > 0)
                {
                    monk = createMonkey(projectiles[projectileCount - 1], pos.x, pos.y, (centerX - pos.x)*10, (centerY - pos.y)*10);
                }

                projectileCount--;

                pos.x = centerX;
                pos.y = centerY;

                grabbed = false;
            }
        }
    }
}

/*******************************************************************************
 Name:              draw
 Description:       Draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void Sling::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(launcherImg, NULL, s, &Slingshot);
    SDL_BlitSurface(image, NULL, s, &loc);
}

Object* Sling::process()
{
    Projectile* m = monk;
    monk = NULL;
    return m;
}

void Sling::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void Sling::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = true;
}
