
#ifndef DrawableObject_H
#define DrawableObject_H

#include "Object.h"
#include <SDL/SDL.h>

class DrawableObject : public Object
{
    protected:
        SDL_Surface* image;
    
    public:
        DrawableObject(const char* file, int , int);
        void draw(SDL_Surface*);

};

#endif
