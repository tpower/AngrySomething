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

/*******************************************************************************
 Name:              PhysicsEngine
 Description:       Default constructor
 ******************************************************************************/
PhysicsEngine::PhysicsEngine()
{
    
}

/*******************************************************************************
 Name:              ~PhysicsEngine
 Description:       Destructor
 ******************************************************************************/
PhysicsEngine::~PhysicsEngine()
{
    
}

/*******************************************************************************
 Name:              run
 Description:       Runs all objects in the room and tests for collisions
 
 Input:
    room            Room& containing objects
 ******************************************************************************/
void PhysicsEngine::run(Room& room)
{
    for(int i = 0; i < room.getNumObjects(); i++)
    {
        Object* obj = room.getObjectAt(i);
        
        obj->run();
        
        if(obj->getPos().x <= 0 || obj->getPos().x + obj->getPos().w >= 640)
        {
//            vect temp = obj->getVel();
//            temp.x *= -1;
//            obj->setVel(temp);
        }
        if(obj->getPos().y <= 0 || obj->getPos().y + obj->getPos().h >= 480)
        {
//            vect temp = obj->getVel();
//            temp.y *= -1;
//            obj->setVel(temp);
        }
    }
}
