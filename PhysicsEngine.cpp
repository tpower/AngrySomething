/*******************************************************************************
 Filename:                  PhysicsEngine.cpp
 Classname:                 PhysicsEngine
 
 Description:               This file declares the PhysicsEngine class. The 
                            PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/

#include <iostream>

#include "PhysicsEngine.h"
#include "PhysicalObject.h"

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
    runObjects(room);
    
    detectCollisions(room);
}

/*******************************************************************************
 Name:              runObjects
 Description:       This method runs every physical object in a given room.
 
 Input:
    room            Room&
 ******************************************************************************/
void PhysicsEngine::runObjects(Room& room)
{
    for(int i = 0; i < room.getNumObjects(); i++)
    {
        Object* obj = room.getObjectAt(i);
        
        if(obj->getType() == PHYSICAL_OBJECT || obj->getType() == MULTI_OBJECT)
        {
            PhysicalObject *pObj = dynamic_cast<PhysicalObject*>(obj);
            
            pObj->run();
            
            handleWallCollision(pObj);
        }
    }
}

/*******************************************************************************
 Name:              detectCollisions
 Description:       This method detects collisions between all PhysicalObjects
                    in a given room.
 
 Input:
    room            Room&
 ******************************************************************************/
void PhysicsEngine::detectCollisions(Room& room)
{
    for(int i = 0; i < room.getNumObjects() - 1; i++)
    {
        Object* obj = room.getObjectAt(i);
        
        if(obj->getType() == PHYSICAL_OBJECT || obj->getType() == MULTI_OBJECT)
        {
            PhysicalObject *pObj = dynamic_cast<PhysicalObject*>(obj);
            
            for(int j = i + 1; j < room.getNumObjects(); j++)
            {
                Object* obj2 = room.getObjectAt(j);
                
                if(obj->getType() == PHYSICAL_OBJECT || obj->getType() == MULTI_OBJECT)
                {
                    PhysicalObject *pObj2 = dynamic_cast<PhysicalObject*>(obj2);
                    
                    if(doCollide(pObj, pObj2))
                    {
                        //TODO: determine side of collision for each object
                        
                        //TODO: tell each object to do something about it
                            //or do something about it yourself?
                        
                        SDL_Delay(100); //temporary
                    }
                }
            }
        }
    }
}

/*******************************************************************************
 Name:              handleWallCollision
 Description:       This method keeps a PhysicalObject from leaving the
                    boundaries of the screen.
 
 Input:
    pObj            PhysicalObject* 
 ******************************************************************************/
void PhysicsEngine::handleWallCollision(PhysicalObject* pObj)
{
    if(pObj->getPos().x <= 0 || pObj->getPos().x + pObj->getPos().w >= 640)
    {
        vect temp = pObj->getVel();
        temp.x *= -1;
        pObj->setVel(temp);
    }
    if(pObj->getPos().y <= 0 || pObj->getPos().y + pObj->getPos().h >= 480)
    {
        vect temp = pObj->getVel();
        temp.y *= -1;
        pObj->setVel(temp);
    }
}

/*******************************************************************************
 Name:              doIntersect
 Description:       Determines if two SDL_Rects intersect
 
 Input:
    a               SDL_Rect
    b               SDL_Rect
 
 Output:
    returns         bool TRUE if SDL_Rects intersect
 ******************************************************************************/
bool PhysicsEngine::doIntersect(SDL_Rect a, SDL_Rect b)
{
    if(a.x + a.w    < b.x)          return false;
    if(a.x          > b.x + b.w)    return false;
    if(a.y + a.h    < b.y)          return false;
    if(a.y          > b.y + b.h)    return false;
    
    return true;
}

/*******************************************************************************
 Name:              doCollide
 Description:       Determines if two PhysicalObjects collided
 
 Input:
    a               PhysicalObject*
    b               PhysicalObject*
 
 Output:
    returns         bool TRUE if PhysicalObjects collided
 ******************************************************************************/
bool PhysicsEngine::doCollide(PhysicalObject *a, PhysicalObject *b)
{
    return doIntersect(a->getPos(), b->getPos());
}
