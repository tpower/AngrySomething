/*******************************************************************************
 Filename:                  PhysicsEngine.h
 Classname:                 PhysicsEngine
 
 Description:               This file declares the PhysicsEngine class. The 
                            PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/

#ifndef AngrySomething_PhysicsEngine_h
#define AngrySomething_PhysicsEngine_h

#include <SDL/SDL.h>

#include "Room.h"
#include "PhysicalObject.h"

class PhysicsEngine
{
    public:
        void run(Room& room);
    
    private:
        void runObjects(Room& room);
        void detectCollisions(Room& room);
    
        void handleWallCollision(PhysicalObject* pObj);
    
        bool doCollide(PhysicalObject* a, PhysicalObject* b);
        void resolveCollision(PhysicalObject* obj, PhysicalObject* obj2);
    
        int  sideOfCollision(PhysicalObject* obj, PhysicalObject* obj2);
        void handleCollision_Box(PhysicalObject* obj, PhysicalObject* obj2, int side);
        void handleCollision_Circle(PhysicalObject* obj, PhysicalObject* obj2);
};

#endif
