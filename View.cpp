/*******************************************************************************
 Filename:                  View.cpp
 Classname:                 View
 
 Description:               This file defines the View class. The View class is
                            responsible for output to the screen. Most of the
                            SDL implementation will belong in this class.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "View.h"
#include <iostream>

/*******************************************************************************
 Name:              View
 Description:       Default constructor for View class
 ******************************************************************************/
View::View() : Base(VIEW)
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
    if (needsUpdate)
    {
        SDL_Flip(screen); //Render screen
        
        //Create new pallete
        
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
    SDL_Rect f = obj.getComp(GRPHCOMP).getFrame();
    SDL_Rect l = obj.getComp(TRANCOMP).getLoc();
    SDL_Surface i = obj.getComp(GRPHCOMP).getImage();
    
//    SDL_Surface* optimized = SDL_DisplayFormat(&i);
    
    SDL_BlitSurface(&i, &f, screen, &l);
    
//    SDL_FreeSurface(optimized);
    
    needsUpdate = true;
}
