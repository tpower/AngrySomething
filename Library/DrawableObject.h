/*******************************************************************************
 Filename:                  DrawableObject.h
 Classname:                 DrawableObject

 Description:               The DrawableObject class is a subclass of Object
                            that can be drawn to the screen.
 ******************************************************************************/

#ifndef DrawableObject_H
#define DrawableObject_H

#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>

#include "Object.h"

class DrawableObject : virtual public Object
{
    protected:
        SDL_Surface*    image;
        SDL_Surface*    message;
        TTF_Font*       font;
        SDL_Color       fontColor;
        int             layer;

    public:
        DrawableObject(const char* file, int);
        ~DrawableObject();

        DrawableObject& operator=(const DrawableObject& other);
    
        int             getLayer();

        virtual void    draw(SDL_Surface*);
};

#endif
