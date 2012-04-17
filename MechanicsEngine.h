#ifndef MECHANICSENGINE_H
#define MECHANICSENGINE_H

#include <SDL/SDL.h>

#include "Room.h"

class MechanicsEngine
{
    private:
        SDL_Event event;

    public:
        int run(Room& room);
};

#endif
