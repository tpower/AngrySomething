/*******************************************************************************
 Filename:                  PhysicsEngine.cpp
 Classname:                 PhysicsEngine

 Description:               This file declares the PhysicsEngine class. The
                            PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/
#include "Game.h"

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
        obj->move();

        if(obj->getPos().x <= 0 || obj->getPos().x + obj->getPos().w >= 640)
        {
            vect temp = obj->getVect();
            temp.xvel *= -1;
            obj->setVect(temp);
        }

        if(obj->getPos().y <= 0 || obj->getPos().y + obj->getPos().h >= 480)
        {
            vect temp = obj->getVect();
            temp.yvel *= -1;
            obj->setVect(temp);
        }
    }
}
