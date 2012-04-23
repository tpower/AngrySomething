#ifndef CLICKABLEOBJECT_H_INCLUDED
#define CLICKABLEOBJECT_H_INCLUDED

#include <SDL/SDL.h>

#include "DrawableObject.h"
#include "MechanicsObject.h"
#include "ControllableObject.h"

#include <string>

using namespace std;

class ClickableObject : public DrawableObject, public ControllableObject, public MechanicsObject
{
    private:
        int value;
        bool clicked;
    public:
        ClickableObject(const char* file, int x, int y, int w, int h, int v);
        ~ClickableObject();

        void        draw(SDL_Surface*);
        int         check();
        void        handle(SDL_Event);
        void        pause();
        void        unpause();
};

#endif // CLICKABLEOBJECT_H_INCLUDED
