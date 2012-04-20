#ifndef CONTROLENGINE_H
#define CONTROLENGINE_H
#include "ControllableObject.h"
#include "Room.h"

class ControlEngine
{
    private:
        SDL_Event event;

    public:
        void run(Room& room);
};

#endif // CONTROLENGINE_H
