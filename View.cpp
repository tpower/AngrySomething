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
#include <iostream>

/*******************************************************************************
 Name:              View
 Description:       Primary constructor for View class
 
 Input:
    bgfile          string representing filepath for background image
 ******************************************************************************/
View::View(string bgFile) : Base("view")
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        cout << "ERROR: View:View:SDL_Init" << endl;
        exit(-1);
    }
    
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    
    if(!screen)
    {
        cout << "ERROR: View:View:SDL_SetVideoMode" << endl;
        exit(-1);
    }
    
    background = SDL_LoadBMP(bgFile.c_str());
    
    if(!background)
    {
        cout << "ERROR: View:View:SDL_LoadBMP" << endl;
        exit(-1);
    }
    
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
View::View(const View& other) : Base("view")
{
    *screen     = *(other.screen);
    *background = *(other.background);
    needsUpdate = other.needsUpdate;
}

/*******************************************************************************
 Name:              ~View
 Description:       Deconstructor for View class
 ******************************************************************************/
View::~View()
{
    SDL_FreeSurface(screen);
    SDL_FreeSurface(background);
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
        *background = *(other.background);
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
    if (needsUpdate)
    {
        SDL_Flip(screen); //Render screen
        
        SDL_BlitSurface(background, NULL, screen, NULL); //Creates new pallete
        
        needsUpdate = false;
    }
}

/*******************************************************************************
 Name:              draw
 Description:       This method draws the given object to the screens buffer
 
 Input:
    obj       const Object&
 ******************************************************************************/
void View::draw(const Object& obj)
{
    SDL_Rect f = obj.getFrame();
    SDL_Rect l = obj.getLoc();
    SDL_Surface i = obj.getImage();
    
//    SDL_Surface* optimized = SDL_DisplayFormat(&i);
    
    SDL_BlitSurface(&i, &f, screen, &l);
    
//    SDL_FreeSurface(optimized);
    
    needsUpdate = true;
}


