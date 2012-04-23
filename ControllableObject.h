#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H
#include <SDL/SDL.h>
#include "Object.h"

class ControllableObject : virtual public Object
{
    public:
        ControllableObject();
        virtual void handle(SDL_Event event);
};

#endif // CONTROLLABLEOBJECT_H
