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
#include "CircleObject.h"

class PhysicsEngine
{
    public:
        void run(Room& room);
    
    private:
        void runObjects(Room& room);
        void detectCollisions(Room& room);
    
        void handleWallCollision(PhysicalObject* pObj);
    
        bool doCollide(PhysicalObject* a, PhysicalObject* b);
        bool doCollide(CircleObject* a, CircleObject* b);
    
        void resolveCollision(PhysicalObject* obj, PhysicalObject* obj2);
        void resolveCollision(CircleObject* obj, CircleObject* obj2);
    
        int  sideOfCollision(PhysicalObject* obj, PhysicalObject* obj2);
    
        void handleCollision_Box(PhysicalObject* obj, PhysicalObject* obj2, int side);
        void handleCollision(CircleObject* obj, CircleObject* obj2);
};

#endif
