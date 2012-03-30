/*******************************************************************************
 Filename:                  PhysicsEngine.cpp
 Classname:                 PhysicsEngine
 
 Description:               This file declares the PhysicsEngine class. The 
                            PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/

#include <iostream>

#include "PhysicsEngine.h"
#include "DrawableObject.h"

PhysicsEngine::PhysicsEngine()
{
    
}

PhysicsEngine::~PhysicsEngine()
{
    
}

void PhysicsEngine::run(Room& room)
{
    for(int i = 0; i < room.getNumObjects(); i++)
    {
        room.getObjectAt(i)->run();
        
//        if(room.getObjectAt(i)->getPosition().x <= 0 || room.getObjectAt(i)->getPosition().x + room.getObjectAt(i)->getPosition().w >= 640)
//        {
//            vect temp = room.getObjectAt(i)->getVel();
//            temp.x *= -1;
//            room.getObjectAt(i)->setVel(temp);
//        }
//        if(room.getObjectAt(i)->getPosition().y <= 0 || room.getObjectAt(i)->getPosition().y + room.getObjectAt(i)->getPosition().h >= 480)
//        {
//            vect temp = room.getObjectAt(i)->getVel();
//            temp.y *= -1;
//            room.getObjectAt(i)->setVel(temp);
//        }
    }
    
    //wall collision (temporary)
    
    
    //check for collisions
}
