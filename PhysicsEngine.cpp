/*******************************************************************************
 Filename:                  PhysicsEngine.cpp
 Classname:                 PhysicsEngine
 
 Description:               This file declares the PhysicsEngine class. The 
                            PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/

#include <iostream>
#include <cmath>

#include "PhysicsEngine.h"

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
        
        if(obj->isPhysical())
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
        
        if(obj->isPhysical())
        {
            PhysicalObject *pObj = dynamic_cast<PhysicalObject*>(obj);
            
            for(int j = i + 1; j < room.getNumObjects(); j++)
            {
                Object* obj2 = room.getObjectAt(j);
                
                if(obj->isPhysical())
                {
                    PhysicalObject *pObj2 = dynamic_cast<PhysicalObject*>(obj2);
                    
                    if(doCollide(pObj, pObj2))
                    {
                        int sideA, sideB;
                        
                        //evaluate side of collision for both objects
                        sideA = sideOfCollision(pObj, pObj2);
                        if(sideA - 4 <= 0)
                            sideB = sideA + 4;
                        else
                            sideB = sideA - 4;
                        
                        //react to collision
                        handleCollision(pObj, pObj2, sideA);
                        handleCollision(pObj2, pObj, sideB);
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
    SDL_Rect pos = pObj->getPos();          //get position
    
    if(pos.x <= 0 || pos.x + pos.w >= 640)  //bounce off left/right wall
    {
        if(pos.x <= 0) pos.x = 1;
        else pos.x = 640 - pos.w - 1;           //adjust position
        pObj->setPos(pos);
        
        vect temp = pObj->getVel();
        temp.x *= -.8;                           //adjust velocity
        pObj->setVel(temp);
    }
    
    if(pos.y <= 0 || pos.y + pos.h >= 480)  //bounce off top/bottom wall
    {
        if(pos.y <= 0) pos.y = 1;
        else pos.y = 480 - pos.h - 1;           //adjust position
        pObj->setPos(pos);
        
        vect temp = pObj->getVel();
        temp.y *= -.8;                           //adjust velocity
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
    //check for cases that make collision impossible
    if(a.x + a.w    < b.x)          return false;
    if(a.x          > b.x + b.w)    return false;
    if(a.y + a.h    < b.y)          return false;
    if(a.y          > b.y + b.h)    return false;
    
    //return true collision
    return true;
}

bool PhysicsEngine::doIntersect(circle a, circle b)
{
//    int dist = sqrt(pow(a.cent.x + b.cent.x, 2) + pow(a.cent.y + b.cent.y, 2));
//    
//    if(dist <= a.rad + b.rad)
//        return true;
//    return false;
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
    //check bounding box collision
    return doIntersect(a->getPos(), b->getPos());
}

/*******************************************************************************
 Name:              sideOfCollision
 ******************************************************************************/
int PhysicsEngine::sideOfCollision(PhysicalObject* obj, PhysicalObject* obj2)
{
    //get bounding boxes
    SDL_Rect a = obj->getPos();
    SDL_Rect b = obj2->getPos();
    
    //assume 4-sided collision
    bool aTop    = true;
    bool aRight  = true;
    bool aBottom = true;
    bool aLeft   = true;
    
    //evaluate initial collision sides  -- DONT CHANGE
    if(a.y > b.y) aBottom  = false;
    if(a.x > b.x) aRight = false;
    if(a.y + a.h < b.y + b.h) aTop = false;
    if(a.x + a.w < b.x + b.w) aLeft  = false;
    
    //evaluate impossible 3-side collision case -- DONT CHANGE
    if(aTop + aBottom + aRight + aLeft == 3)
    {
        if(aTop && aBottom)
            aTop = aBottom = false;
        else
            aLeft = aRight = false;
    }
    
    //evaluate corner case
    if(aTop + aBottom + aRight + aLeft == 2)
    {
        vect velA = obj->getVel();
        vect velB = obj2->getVel();
        
        if(velA.y && velB.y)
        {
            if(velA.y <= velB.y) aBottom    = false;
            if(velA.y >= velB.y) aTop       = false;
        }
        else
        {
            if(velA.y - velB.y > 0) aTop    = false;
            if(velA.y - velB.y < 0) aBottom = false;
            
            if(velA.y - velB.y == 0) aTop = aBottom = false;
        }
        
        if(velA.x && velB.x)
        {
            if(velA.x <= velB.x) aRight     = false;
            if(velA.x >= velB.x) aLeft      = false;
        }
        else
        {
            if(velA.x - velB.x > 0) aLeft   = false;
            if(velA.x - velB.x < 0) aRight  = false;
            
            if(velA.x - velB.x == 0) aLeft = aRight = false;
        }
        
//        if(velA.y <= velB.y) aBottom    = false;
//        if(velA.y >= velB.y) aTop       = false;
//        
//        if(velA.x <= velB.x) aRight     = false;
//        if(velA.x >= velB.x) aLeft      = false;
    }
    
    //evaluate outstanding corner case
    if(aTop + aBottom + aRight + aLeft == 2)
    {
        double hDiff, wDiff;
        vect velA = obj->getVel();
        vect velB = obj2->getVel();
        
        if(aTop)
            hDiff = (b.y + b.h - a.y);
        else
            hDiff = (a.y + a.h - b.y);
        
        if(aLeft)
            wDiff = (b.x + b.w - a.x);
        else
            wDiff = (a.x + a.w - b.x);
        
        if(abs(velA.y) + abs(velB.y))
            hDiff /= abs(velA.y) + abs(velB.y);
        else
            hDiff = 0;
        
        if(abs(velA.x) + abs(velB.x))
            wDiff /= abs(velA.x) + abs(velB.x);
        else
            wDiff = 0;
        
        if(hDiff > wDiff)
            aTop = aBottom = false;
        else if(hDiff < wDiff)
            aLeft = aRight = false;
    }
    
    //return collision code
    if(aTop)
    {
        if(aLeft)   return TOP_LEFT;
        if(aRight)  return TOP_RIGHT;
        return TOP;
    }
    if(aBottom)
    {
        if(aLeft)   return BOTTOM_LEFT;
        if(aRight)  return BOTTOM_RIGHT;
        return BOTTOM;
    }
    if(aLeft) return LEFT;
    return RIGHT;
}

/*******************************************************************************
 Name:              handleCollision
 ******************************************************************************/
void PhysicsEngine::handleCollision(PhysicalObject* obj, PhysicalObject* obj2, int side)
{
    //react to horizontal collision
    if(side == TOP || side == BOTTOM)
    {
        vect v = obj2->getVel();
        v.x = 0;
        obj->applyForce(obj2->getMass(), v);
    }
    
    //react to vertical collision
    else if(side == LEFT || side == RIGHT)
    {
        vect v = obj2->getVel();
        v.y = 0;
        obj->applyForce(obj2->getMass(), v);
    }
    
    else
    {
        vect v = obj2->getVel();
        obj->applyForce(obj2->getMass(), v);
    }
}

void PhysicsEngine::handleCollision(PhysicalObject* obj, PhysicalObject* obj2)
{
//    circle a, b;
//    vect velB;
//    double vf;
//    
//    double theta = 1 / tan((b.cent.x - a.cent.x) / (b.cent.y - a.cent.y));
//    double lamda = 1 / tan(velB.x / velB.y);
//    
//    vf = obj2->getVel() * cos(theta - lamda);
}
