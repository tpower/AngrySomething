#include "MechanicsEngine.h"
#include "Object.h"
#include "MechanicsObject.h"
#include "Pig.h"
#include "Projectile.h"
#include "Sling.h"

void MechanicsEngine::run(Room& room)
{
    int state = 0;
    Object* obj;
    Object* objTemp = NULL;

    for(int i = 0; i < room.getNumObjects() && !state; i++)
    {
        obj = room.getObjectAt(i);

        if(obj->isMechanical())
        {
            objTemp = dynamic_cast<MechanicsObject*>(obj)->process();
            if(objTemp)
            {
                room.add(objTemp);
            }
        }
    }

}
