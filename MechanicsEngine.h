#ifndef MECHANICSENGINE_H
#define MECHANICSENGINE_H
#include "Object.h"
#include "Room.h"

class MechanicsEngine
{
    private:
        SDL_Event event;
    public:
        void run(Room& room);
};

#endif // MECHANICSENGINE
