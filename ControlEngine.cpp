/*******************************************************************************
 Filename:                  ControlEngine.h
 Classname:                 ControlEngine
 ******************************************************************************/

#include "ControlEngine.h"

/*******************************************************************************
 Name:              run
 Description:       This method handles user events for all ControllableObjects
                    in the room
 
 Input:
    room            Room& containing ControllableObjects
 ******************************************************************************/
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

            if(obj->isControllable() && obj->getActiveCont())
            {
                dynamic_cast<ControllableObject*>(obj)->handle(event);
            }
        }
    }
}
