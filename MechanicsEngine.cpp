
#include "MechanicsEngine.h"
#include "Object.h"
#include "MechanicsObject.h"
#include "Pig.h"
#include "Projectile.h"
#include "Sling.h"

int MechanicsEngine::run(Room& room)
{
    int state = 0;
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
            }
        }
    }

    if(Pig::getNumPigs() <= 0)
    {
        state = 1;
    }

    if(Projectile::getNumBirds() <= 0 && Sling::getProjectileCount() <= 0)
    {
        state = -1;
    }

    return state;
}
