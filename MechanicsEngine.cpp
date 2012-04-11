
#include "MechanicsEngine.h"
#include "Object.h"
#include "MechanicsObject.h"

void MechanicsEngine::run(Room& room)
{
    if(SDL_PollEvent(&event))
    {
        if( event.type == SDL_QUIT )
        {
            exit(0);
        }

        for(int i = 0; i < room.getNumObjects(); i++)
        {
            Object* obj = room.getObjectAt(i);
            Object* temp = NULL;

            if(obj->isMechanical())
            {
                temp = dynamic_cast<MechanicsObject*>(obj)->handle(event);
                if(temp)
                {
                    room.add(temp);
                }

                if(obj->getState() == -1)
                {
                    room.remove(i);
                }
            }

        }
    }
}
