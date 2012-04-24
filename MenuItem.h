/*******************************************************************************
 Filename:                  MenuItem.h
 Classname:                 MenuItem
 
 Description:               
 ******************************************************************************/

#ifndef MENUITEM_H_INCLUDED
#define MENUITEM_H_INCLUDED

#include <SDL/SDL.h>
#include <string>

#include "DrawableObject.h"
#include "MechanicsObject.h"
#include "ControllableObject.h"

using namespace std;

class MenuItem : public DrawableObject, public ControllableObject,
                 public MechanicsObject
{
    private:
        int value;
        bool clicked;
    
    public:
        MenuItem(const char* file, int x, int y, int w, int h, int v);

        void        draw(SDL_Surface*);
        int         check();
        void        handle(SDL_Event);
        void        pause();
        void        unpause();
};

#endif
