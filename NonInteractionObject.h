/*******************************************************************************
 Filename:                  NonInteractionObject.h
 Classname:                 NonInteractionObject
 
 Description:               
 ******************************************************************************/

#ifndef NONINTERACTIONOBJECT_H_INCLUDED
#define NONINTERACTIONOBJECT_H_INCLUDED

#include <SDL/SDL.h>
#include <string>

#include "DrawableObject.h"

using namespace std;

class NonInteractionObject : public DrawableObject
{
    private:
        int value;
        bool clicked;
    
    public:
        NonInteractionObject(const char* file, int x, int y);

        void        draw(SDL_Surface*);
        void        pause();
        void        unpause();
};


#endif
