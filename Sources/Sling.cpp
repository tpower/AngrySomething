/*******************************************************************************
 Filename:                  Sling.h
 Classname:                 Sling

 Description:               This file implements the Sling class. This class
                            is an object capable of taking user input to direct
                            the slings angle, and spawn a bird at the proper
                            velocity and position.
 ******************************************************************************/

#include <cmath>

#include "Sling.h"
#include "UFObird.h"

int Sling::projectileCount = 0;

/*******************************************************************************
    Name:                   Constructor
    Description:            Constructs a Sling class
    Input:
            const char*     the name of the bitmap file for the graphics
            int             the x position of the object on the screen
            int             the y position of the object on the screen
            string          string indicating the order of ammunition to be fired

    Output:
            None

 ******************************************************************************/
Sling::Sling(const char* file, const char* file2, int x, int y, string ammo)
    :   Object(x, y, 180, 150),
        DrawableObject(file, 2),
        MechanicsObject()
{
    grabbed = false;

    // loads the image of the object
    launcherImg = SDL_LoadBMP(file2);
    // sets position of the slingshot
    Slingshot.x = x - 25;
    Slingshot.y = y;

    // sets radius of the fire area
    radius = 75;

    monk = NULL;

    // loads ammo for the slingshot to fire
    projectiles = ammo;
    projectileCount = (int)projectiles.length();

    type = 1;

    // sets which engines should manipulate it
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = true;

    centerX = pos.x;
    centerY = pos.y;
}

/*******************************************************************************
    Name:               Deconstructor
    Description:        Desconstructs the object, freeing it's image surface used
                        for drawing
    Input:
                        None
    Output:
                        None

 ******************************************************************************/
Sling::~Sling()
{
    SDL_FreeSurface(launcherImg);
}

/*******************************************************************************
    Name:                   checkBounds
    Description:            Checks to see if the mouse is currently near enough
                            to the Sling to interact with it.
    Input:
            SDL_Event       represents the mouse event inputted by user

    Output:
            Returns         a boolean indicating whether the mouse was in the
                            bounds of the Sling.

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
    Name:                   createMonkey
    Description:            Creates and returns a Monkey with correct position,
                            velocity, and acceleration
    Input:
            char            represents the type of projectile to be spawned
            int             represents the x spawn position of the projectile
            int             represents the y spawn position of the projectile
            int             represents the x spawn velocity of the projectile
            int             represents the y spawn velocity of the projectile

    Output:
            Projectile*     a pointer to the projectile to be added to the room
                            array
******************************************************************************/
Projectile* Sling::createMonkey(char type, int xPos, int yPos, int xVel, int yVel)
{
    Projectile* p;

    switch (type)
    {
        case 'N':
            p = new Projectile("Assets/Art/GameArt/Monkey.bmp", xPos, yPos, xVel, yVel);
            break;
        case 'U':
            p = new UFObird("Assets/Art/IntroCutscene/AngryBird.bmp", "Assets/Art/IntroCutscene/UFO.bmp", xPos, yPos, xVel, yVel);
            break;
    }

    return p;
}


/*******************************************************************************
    Name:                   Handle
    Description:            Overridden handle method. Handles user input,
                            spawning a projectile based on the moust position
                            and whether or not it is clicked.
    Input:
            SDL_Event       an SDL_Event storing the user input to be handled

    Output:
            None

 ******************************************************************************/
void Sling::handle(SDL_Event e)
{
    monk = NULL;
    static bool grabbed = false;

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
                    monk = createMonkey(projectiles[projectileCount - 1], pos.x, pos.y, (centerX - pos.x)*.5, (centerY - pos.y)*.4);
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
    Name:                   Draw
    Description:            Overridden draw method. Draws the Object to the
                            screen. Displays both the sling and the strechy
                            component of it.
    Input:
            SDL_Surface*    a SDL_Surface* representing the screen

    Output:
            None

 ******************************************************************************/
void Sling::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    Uint32 colorkey1 = SDL_MapRGB(image->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey1);

    Uint32 colorkey2 = SDL_MapRGB(launcherImg->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey(launcherImg, SDL_SRCCOLORKEY, colorkey2);

    SDL_BlitSurface(launcherImg, NULL, s, &Slingshot);
    SDL_BlitSurface(image, NULL, s, &loc);

    char buffer[10];
    sprintf(buffer,"%d",getScore());

    message = TTF_RenderText_Solid(font, buffer, fontColor);

    static SDL_Rect scoreLoc;
    scoreLoc.x = 1100;
    scoreLoc.y = 30;

    SDL_BlitSurface(message, NULL, s, &scoreLoc);
}

/*******************************************************************************
    Name:                   Process
    Description:            Overidden function of the MechanicsObject class.
                            Returns a projectile if one is created
    Input:
            None

    Output:
            Returns         an Object* of an Object that needs to be added to the
                            array of Object* in Room.

 ******************************************************************************/
Object* Sling::process()
{
    Projectile* m = monk;
    monk = NULL;
    return m;
}

/*******************************************************************************
    Name:                   pause
    Description:            Turns off all of the components of the Object that
                            get handled by engines except for Graphics.
    Input:
            None

    Output:
            None

 ******************************************************************************/
void Sling::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
    Name:                   unpause
    Description:            Turns on all of the components of the Object that
                            get handled by engines for this specific Object.
    Input:
            None

    Output:
            None

 ******************************************************************************/
void Sling::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = true;
}
