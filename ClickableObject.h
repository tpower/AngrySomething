#ifndef CLICKABLEOBJECT_H_INCLUDED
#define CLICKABLEOBJECT_H_INCLUDED

#include <SDL/SDL.h>

#include "DrawableObject.h"
#include "MechanicsObject.h"

#include <string>

using namespace std;

class ClickableObject : public DrawableObject, public MechanicsObject
{
    private:
        int value;
    public:
        ClickableObject(const char* file, int x, int y, int w, int h, int v);
        ~ClickableObject();

        void        draw(SDL_Surface*);
        int     handleU(SDL_Event);
};

#endif // CLICKABLEOBJECT_H_INCLUDED
