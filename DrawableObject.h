/*******************************************************************************
 Filename:                  DrawableObject.h
 Classname:                 DrawableObject
 
 Description:               This file declares the DrawableObject class.
 ******************************************************************************/

#ifndef DrawableObject_H
#define DrawableObject_H

#include <SDL/SDL.h>

#include "Object.h"

class DrawableObject : public Object
{
    protected:
        SDL_Surface* image;
    
    public:
        DrawableObject(const char* file, int x, int y);
        DrawableObject(const DrawableObject& other);
        ~DrawableObject();
    
        DrawableObject& operator=(const DrawableObject& other);
    
        void            draw(SDL_Surface*);

};

#endif
