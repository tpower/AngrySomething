/*******************************************************************************
 Filename:                  View.cpp
 Classname:                 View
 
 Description:               This file defines the View class. The View class is
                            responsible for output to the screen. Most of the
                            SDL implementation will belong in this class.
 ******************************************************************************/

#include "View.h"
#include "Object.h"

/*******************************************************************************
 Name:              View
 Description:       Default constructor for View class
 ******************************************************************************/
View::View() : Base(VIEW)
{
    SDL_Surface *background = NULL;
    
    //start SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        exit(-1);
    }
    
    //set up screen
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    if(!screen)
    {
        exit(-1);
    }
    
    //load background image
    background = SDL_LoadBMP("object.bmp");
    
    //apply image to screen
    SDL_BlitSurface(background, NULL, screen, NULL);
    
    //update screen
    SDL_Flip(screen);
    
    //free background image
    SDL_FreeSurface(background);
    
    needsUpdate = true;
}

/*******************************************************************************
 Name:              View
 Description:       Copy constructor for View class
 
 Input:
    other           View to be copied
 ******************************************************************************/
View::View(const View& other) : Base(VIEW)
{
    *screen     = *(other.screen);
    needsUpdate = other.needsUpdate;
}

/*******************************************************************************
 Name:              ~View
 Description:       Deconstructor for View class
 ******************************************************************************/
View::~View()
{
    SDL_FreeSurface(screen);
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for View class
 
 Input:
    other           const View&
 ******************************************************************************/
View View::operator=(const View& other)
{
    if(&other != this)
    {
        *screen     = *(other.screen);
        needsUpdate = other.needsUpdate;
    }
    
    return *this;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the screen
 ******************************************************************************/
void View::update()
{
    if(needsUpdate)
    {
        SDL_Flip(screen);
        needsUpdate = false;
    }
}

/*******************************************************************************
 Name:              draw
 Description:       This method draws the given object to the screens buffer
 
 Input:
    obj       const Object&
 ******************************************************************************/
void View::draw(Object* obj)
{
    SDL_Surface *i  = NULL;
    
    SDL_BlitSurface(i, NULL, screen, NULL);
    
    needsUpdate = true;
}
