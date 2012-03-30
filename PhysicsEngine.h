/*******************************************************************************
 Filename:                  PhysicsEngine.h
 Classname:                 PhysicsEngine
 
 Description:               This file declares the PhysicsEngine class. The 
                            PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/

#ifndef AngrySomething_PhysicsEngine_h
#define AngrySomething_PhysicsEngine_h

#include "Room.h"

class PhysicsEngine
{
    private:
    
    public:
        PhysicsEngine();
        ~PhysicsEngine();
        void run(Room& room);
};

#endif
