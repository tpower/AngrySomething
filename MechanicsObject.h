
#ifndef AngrySomething_MechanicsObject_h
#define AngrySomething_MechanicsObject_h

#include <SDL/SDL.h>

#include "Object.h"

class MechanicsObject : virtual public Object
{
    private:
        bool grabbed;
    
    public:
        virtual void handle(SDL_Event e);
};

#endif
