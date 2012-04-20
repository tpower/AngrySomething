#include "ControlEngine.h"

void ControlEngine::run(Room& room)
{
    Object* obj;

    if(SDL_PollEvent(&event))
    {
        if( event.type == SDL_QUIT )
        {
            exit(0);
        }

        for(int i = 0; i < room.getNumObjects(); i++)
        {
            obj = room.getObjectAt(i);

            if(obj->isControllable())
            {
                dynamic_cast<ControllableObject*>(obj)->handle(event);
            }
        }
    }
}
