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

#include <iostream>

#include "View.h"
#include "Object.h"
#include "TranComp.h"
#include "GrphComp.h"

/*******************************************************************************
 Name:              View
 Description:       Default constructor for View class
 ******************************************************************************/
View::View() : Base(VIEW)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        cout << "ERROR: View:View:SDL_Init" << endl;
        exit(-1);
    }
    
    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
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
    GrphComp *grph = static_cast<GrphComp*>(obj->getComp(GRPHCOMP));
    TranComp *tran = static_cast<TranComp*>(obj->getComp(TRANCOMP));
    
    SDL_Rect f      = grph->getFrame();
    SDL_Rect l      = tran->getPos();
    SDL_Surface *i  = SDL_DisplayFormat(grph->getImage());
    
    SDL_BlitSurface(i, &f, screen, &l);
    
    needsUpdate = true;
}
