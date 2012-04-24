/*******************************************************************************
 Filename:                  MechanicsEngine.h
 Classname:                 MechanicsEngine
 
 Description:               The MechanicsEngine class handles the game mechanics
                            events within the game.
 ******************************************************************************/

#include "MechanicsEngine.h"
#include "MechanicsObject.h"

/*******************************************************************************
 Name:              run
 Description:       This method processes all MechanicalObjects in the room
 
 Input:
    room            Room& containing MechanicalObjects
 ******************************************************************************/
void MechanicsEngine::run(Room& room)
{
    int state = 0;
    Object* obj;
    Object* objTemp = NULL;

    for(int i = 0; i < room.getNumObjects() && !state; i++)
    {
        obj = room.getObjectAt(i);

        if(obj->isMechanical() && obj->getActiveMech())
        {
            objTemp = dynamic_cast<MechanicsObject*>(obj)->process();
            if(objTemp)
            {
                room.add(objTemp);
            }
        }
    }
}
