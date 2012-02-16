/*******************************************************************************
 Filename:                  View.cpp
 Classname:                 View
 
 Description:               This file defines the View class. The View class is
                            responsible for output to the screen. Most of the
                            SDL implementation will belong in this class.
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "View.h"

/*******************************************************************************
 Name:              View
 Description:       Primary constructor for View class
 
 Input:
    bgfile          string representing filepath for background image
 ******************************************************************************/
View::View(string bgFile) : Base("view")
{
    //Set video mode for screen
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    
    //Load background image
    background = SDL_LoadBMP(bgFile.c_str());
    
    //Prepare first render
    SDL_BlitSurface(background, NULL, screen, NULL);
    needsUpdate = true;
}

/*******************************************************************************
 Name:              View
 Description:       Copy constructor for View class
 
 Input:
    other           View to be copied
 ******************************************************************************/
View::View(const View&) : Base("view")
{
    
}

/*******************************************************************************
 Name:              ~View
 Description:       Deconstructor for View class
 ******************************************************************************/
View::~View()
{
    if(screen) delete screen;
    if(background) delete background;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the screen
 ******************************************************************************/
void View::update()
{
    if (needsUpdate)
    {
        SDL_Flip(screen); //Render screen
        
        SDL_BlitSurface(background, NULL, screen, NULL); //Creates new pallete
        
        needsUpdate = false;
    }
}

