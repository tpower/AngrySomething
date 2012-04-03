#include "MechanicsEngine.h"

void MechanicsEngine::run(Room& room)
{
    if(SDL_PollEvent(&event))
    {
        for(int i = 0; i < room.getNumObjects(); i++)
        {
            Object* obj = room.getObjectAt(i);
            obj->update(event);
        }
    }
}
