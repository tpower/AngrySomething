/*******************************************************************************
 Filename:                  View.h
 Classname:                 View
 
 Description:               This file declares the View class. The View class is
                            responsible for output to the screen. Most of the
                            SDL implementation will belong in this class.
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_View_h
#define AngrySomething_View_h

#include <SDL/SDL.h>
#include <string>

#include "Base.h"

using namespace std;

class View : public Base
{
    private:
        SDL_Surface*    screen;
        SDL_Surface*    background;
        bool            needsUpdate;
    
    public:
        View(string);
        View(const View&);
        ~View();
    
        void update();
};

#endif
