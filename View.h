/*******************************************************************************
 Filename:                  View.h
 Classname:                 View
 
 Description:               This file declares the View class. The View class is
                            responsible for output to the screen. Most of the
                            SDL implementation will belong in this class.
 ******************************************************************************/

#ifndef AngrySomething_View_h
#define AngrySomething_View_h

#include <SDL/SDL.h>

#include "Base.h"

class Object;

class View : public Base
{
    private:
        SDL_Surface*    screen;
        bool            needsUpdate;
    
    public:
        View();
        View(const View&);
        ~View();
    
        View operator=(const View& other);
    
        void update();
        void draw(Object* obj);
};

#endif
