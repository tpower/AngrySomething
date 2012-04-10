
#ifndef AngrySomething_MechanicsObject_h
#define AngrySomething_MechanicsObject_h

#include <SDL/SDL.h>

#include "Object.h"

class MechanicsObject : virtual public Object
{
    private:
        bool grabbed;

    public:
        MechanicsObject();
        virtual Object* handle(SDL_Event e);
};

#endif
