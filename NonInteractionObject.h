#ifndef NONINTERACTIONOBJECT_H_INCLUDED
#define NONINTERACTIONOBJECT_H_INCLUDED

#include <SDL/SDL.h>

#include "DrawableObject.h"

#include <string>

using namespace std;

class NonInteractionObject : public DrawableObject
{
    private:
        int value;
        bool clicked;
    public:
        NonInteractionObject(const char* file, int x, int y);
        ~NonInteractionObject();

        void        draw(SDL_Surface*);
        void        pause();
        void        unpause();
};


#endif // NONINTERACTIONOBJECT_H_INCLUDED
