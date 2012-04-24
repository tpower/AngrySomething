/*******************************************************************************
 Filename:                  UFObird.h
 Classname:                 UFObird

 Description:               This file defines the UFObird class. This class
                            is used in the scripted cutscene and spawns an
                            AngryBird which is abducted by aliens.
 ******************************************************************************/

#include <cmath>

/*******************************************************************************
    Name:                   Constructor
    Description:            Constructs a UFOBird class
    Input:
            const char*     the name of the bitmap file for the UFO graphic
            const char*     the name of the bitmap file for the Bird graphic
            int             the x position of the object on the screen
            int             the y position of the object on the screen
            int             the initial x velocity of the object
            int             the initial y velocity of the object

    Output:
            None

 ******************************************************************************/
UFObird::UFObird(const char* file, const char* file2, int x, int y, int vx, int vy)
    :   Object(x, y, 36, 36),
        Projectile(file, x, y, vx, vy)
{
    type = 1;
    numBirds++;
    image2 = file2;
    UFOactive = false;

    activeDraw = true;
    activePhys = true;
    activeMech = true;
    activeCont = false;
}

/*******************************************************************************
    Name:                   Destructor
    Description:            Destructs the UFPbird and decrements the static
                            bird counter.
    Input:
            None

    Output:
            None

 ******************************************************************************/
UFObird::~UFObird()
{
    numBirds--;
}

/*******************************************************************************
    Name:                   Run
    Description:            Overridden function of the PhysicalObject class.
                            Calls the move method of the PhysicalObject class
                            which it inherits from then checks to see if the
                            velocity of the Object is less than 1. If that is
                            case, the state is set to -1 indicating it needs to
                            be removed.
    Input:
            None

    Output:
            None

 ******************************************************************************/
void UFObird::run()
{
    move();

    if(pow((pow(vel.y,2) + pow(vel.x, 2)), .5) < 1)
    {
        state = -1;
    }
}

/*******************************************************************************
    Name:                   Process
    Description:            Overidden function of the MechanicsObject class. Checks to
                            if the UFObird class is in the correct spot to activate the
                            UFO scripted event
    Input:
            None

    Output:
            Returns         an Object* of an Object that needs to be added to the
                            array of Object* in Room.

 ******************************************************************************/
Object* UFObird::process()
{
    if(pos.x >= 700 and pos.y >= 25)
    {
        UFOactive = true;
        vel.x = 0;
        vel.y = -1;
        acc.x = 0;
        acc.y = -1;
        pos.x = 700;
    }

    return NULL;
}

/*******************************************************************************
    Name:                   Draw
    Description:            Overridden draw method. Draws the Object to the
                            screen. UFObirds display two images, the bird and
                            the UFO which consumes it once the script is
                            activated.
    Input:
            SDL_Surface*    a SDL_Surface* representing the screen

    Output:
            None

 ******************************************************************************/
void UFObird::draw(SDL_Surface* s)
{
    SDL_Rect temp;
    static SDL_Rect loc;
    loc = pos;

    temp.x = 600;
    temp.w = 200;
    temp.y = 10;
    temp.h = 100;

    Spaceship = SDL_LoadBMP(image2);

    if(!image2)
    {
        exit(0);
    }

    Uint32 colorkey = SDL_MapRGB( Spaceship->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey( Spaceship, SDL_SRCCOLORKEY, colorkey );

    SDL_BlitSurface(image, NULL, s, &loc);
    if(UFOactive)
        SDL_BlitSurface(Spaceship, NULL, s, &temp);
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
void UFObird::pause()
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
void UFObird::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = true;
    activeCont = false;
}
