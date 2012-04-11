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
                        
                        if(sideA)
                        {
                            //determine side of obj2 
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
    //get position
    SDL_Rect pos = pObj->getPos();
    
    //bounce off left/right wall
    if(pos.x <= 0 || pos.x + pos.w >= 640)
    {
        //adjust position to avoid post-collision issues
        if(pos.x <= 0)
        {
            pos.x = 1;
            pObj->setCollisionSide(LEFT);
        }
        else
        {
            pos.x = 640 - pos.w - 1;
            pObj->setCollisionSide(RIGHT);
        }
        pObj->setPos(pos);
        
        //adjust velocity
        vect v = pObj->getVel();
        v.x *= -1;
        v.y = 0;
        pObj->applyForce(pObj->getMass(), v, 0);
    }
    
    //bounce off top/bottom wall
    if(pos.y <= 0 || pos.y + pos.h >= 480)
    {
        //adjust position to avoid post-collision issues
        if(pos.y <= 0)
        {
            pos.y = 1;
            pObj->setCollisionSide(TOP);
        }
        else
        {
            pos.y = 480 - pos.h - 1;
            pObj->setCollisionSide(BOTTOM);
        }
        pObj->setPos(pos);
        
        //adjust velocity
        vect v = pObj->getVel();
        v.y *= -1;
        v.x = 0;
        pObj->applyForce(pObj->getMass(), v, 1);
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
    return false;
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
    
    //eliminate impossible corner cases
    if(aTop + aBottom + aRight + aLeft == 2)
    {
        vect velA = obj->getVel();
        vect velB = obj2->getVel();
        
        //avoid getting trapped within objects
        if(velA.x > 0 && velB.x < 0) aLeft      = false;
        if(velA.x < 0 && velB.x > 0) aRight     = false;
        if(velA.y > 0 && velB.y < 0) aTop       = false;
        if(velA.y < 0 && velB.y > 0) aBottom    = false;
        
        //impossible collision case
        if(velA.x == velB.x) aLeft = aRight = false;
        if(velA.y == velB.y) aTop = aBottom = false;
        
        //avoid side-by-side motionless collisions
        if(!velA.x && !velB.x && (a.x == b.x + b.w || a.x == b.x - a.w))
            aLeft = aRight = aTop = aBottom = false;
        if(!velA.y && !velB.y && (a.y == b.y + b.h || a.y == b.y - a.h))
            aLeft = aRight = aTop = aBottom = false;
    }
    
    //evaluate corner case
    if(aTop + aBottom + aRight + aLeft == 2)
    {
        vect velA = obj->getVel();
        vect velB = obj2->getVel();
        
        double tx, ty;
        
        if(aTop)
        {
            ty = abs(a.y - (b.y + b.h)) / abs(velA.y - velB.y);
        }
        else if(aBottom)
        {
            ty = abs((a.y + a.h) - b.y) / abs(velA.y - velB.y);
        }
        
        if(aLeft)
        {
            tx = abs(a.x - (b.x + b.w)) / abs(velA.x - velB.x);
        }
        else if(aRight)
        {
            tx = abs((a.x + a.w) - b.x) / abs(velA.x - velB.x);
        }
        
        if(ty > tx)
        {
            aTop = aBottom = false;
        }
        else if(ty < tx)
        {
            aLeft = aRight = false;
        }
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
    if(aLeft)   return LEFT;
    if(aRight)  return RIGHT;
    return NO_COLLISION;
}

/*******************************************************************************
 Name:              handleCollision
 ******************************************************************************/
void PhysicsEngine::handleCollision(PhysicalObject* obj, PhysicalObject* obj2, int side)
{
    if(side == TOP || side == BOTTOM)
    {
        //adjust position to avoid post-collision problem
        SDL_Rect a = obj->getPos();
        if(side == TOP) a.y++;
        else a.y--;
        obj->setPos(a);
        
        //adjust velocity based on force of collision
        vect v = obj2->getVel();
        v.x = 0;
        obj->applyForce(obj2->getMass(), v, 1);
    }
    else if(side == LEFT || side == RIGHT)
    {
        //adjust position to avoid post-collision problem
        SDL_Rect a = obj->getPos();
        if(side == LEFT) a.x++;
        else a.x--;
        obj->setPos(a);
        
        //adjust velocity based on force of collision
        vect v = obj2->getVel();
        v.y = 0;
        obj->applyForce(obj2->getMass(), v, 0);
    }
    else
    {
        //adjust velocity based on force of collision
        vect v = obj2->getVel();
        obj->applyForce(obj2->getMass(), v, 2);
    }
    
    //record collision side
    obj->setCollisionSide(side);
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
