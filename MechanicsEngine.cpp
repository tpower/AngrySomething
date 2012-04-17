
#include "MechanicsEngine.h"
#include "Object.h"
#include "MechanicsObject.h"
#include "Pig.h"
#include "Projectile.h"
#include "Sling.h"

int MechanicsEngine::run(Room& room)
{
    int state = 0;
    Object* obj;
    Object* objTemp;
    if(SDL_PollEvent(&event))
    {
        if( event.type == SDL_QUIT )
        {
            exit(0);
        }

        for(int i = 0; i < room.getNumObjects() && !state; i++)
        {
            obj = room.getObjectAt(i);
            objTemp = NULL;

            if(obj->isMechanical())
            {
                if(obj->getType() == 1)
                {
                    objTemp = dynamic_cast<MechanicsObject*>(obj)->handle(event);
                    if(objTemp)
                    {
                        room.add(objTemp);
                    }
                }
                else if(obj->getType() == 2)
                {
                    state = dynamic_cast<MechanicsObject*>(obj)->handleU(event);
                }
            }
        }
    }
    //If the room is a level
    if(room.getRoomType() == 1)
    {
        if(Pig::getNumPigs() <= 0)
        {
            //Win Condition
            state = -2;
        }

        if(Projectile::getNumBirds() <= 0 && Sling::getProjectileCount() <= 0)
        {
            //Lose Condition
            state = -1;
        }
    }
    return state;
}
