/*******************************************************************************
 Filename:                  PhysicsEngine.h
 Classname:                 PhysicsEngine
 
 Description:               The PhysicsEngine class is responsible for moving
                            objects and detecting collisions within the room.
 ******************************************************************************/

#include <cmath>

#include "PhysicsEngine.h"
#include "Geometry.h"

const int FIELD_W = 1280;
const int FIELD_H = 700;

/*******************************************************************************
 Name:              run
 Description:       Runs all objects in the room and tests for collisions
 
 Input:
    room            Room& containing PhysicalObjects
 ******************************************************************************/
void PhysicsEngine::run(Room& room)
{
    runObjects(room);
    detectCollisions(room);
}

/*******************************************************************************
 Name:              runObjects
 Description:       This method runs every physical object in a given room
 
 Input:
    room            Room& containing PhysicalObjects
 ******************************************************************************/
void PhysicsEngine::runObjects(Room& room)
{
    for(int i = 0; i < room.getNumObjects(); i++)
    {
        Object* obj = room.getObjectAt(i);

        if(obj->isPhysical() && obj->getActivePhys())
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
                    in a given room
 
 Input:
    room            Room& containing PhysicalObjects
 ******************************************************************************/
void PhysicsEngine::detectCollisions(Room& room)
{
    for(int i = 0; i < room.getNumObjects() - 1; i++)
    {
        Object* obj = room.getObjectAt(i);

        if(obj->isPhysical() && obj->getActivePhys())
        {
            PhysicalObject *pObj = dynamic_cast<PhysicalObject*>(obj);

            for(int j = i + 1; j < room.getNumObjects(); j++)
            {
                Object* obj2 = room.getObjectAt(j);

                if(obj2->isPhysical() && obj2->getActivePhys())
                {
                    PhysicalObject *pObj2 = dynamic_cast<PhysicalObject*>(obj2);

                    if(pObj->getShape() == CIRCLE && pObj2->getShape() == CIRCLE)
                    {
                        if(doCollide((CircleObject*)pObj, (CircleObject*)pObj2))
                            resolveCollision((CircleObject*)pObj, (CircleObject*)pObj2);
                    }
                    else
                    {
                        if(doCollide(pObj, pObj2))
                            resolveCollision(pObj, pObj2);
                    }
                }
            }
        }
    }
}

/*******************************************************************************
 Name:              handleWallCollision
 Description:       This method keeps a PhysicalObject from leaving the
                    boundaries of the screen
 
 Input:
    pObj            PhysicalObject* to test for wall collisions
 ******************************************************************************/
void PhysicsEngine::handleWallCollision(PhysicalObject* pObj)
{
    //get position
    SDL_Rect pos = pObj->getPos();

    //bounce off left/right wall
    if(pos.x <= 0 || pos.x + pos.w >= FIELD_W)
    {
        //adjust position to avoid post-collision issues
        if(pos.x <= 0)
        {
            pos.x = 1;
            pObj->setCollisionSide(LEFT);
        }
        else
        {
            pos.x = FIELD_W - pos.w - 1;
            pObj->setCollisionSide(RIGHT);
        }
        pObj->setPos(pos);

        //adjust velocity
        Vect v = pObj->getVel();
        v.x *= -1;
        v.y = 0;
        pObj->applyForce(pObj->getMass(), v, 0);
    }

    //bounce off top/bottom wall
    if(pos.y <= 0 || pos.y + pos.h >= FIELD_H)
    {
        //adjust position to avoid post-collision issues
        if(pos.y <= 0)
        {
            pos.y = 1;
            pObj->setCollisionSide(TOP);
        }
        else
        {
            pos.y = FIELD_H - pos.h - 1;
            pObj->setCollisionSide(BOTTOM);
        }
        pObj->setPos(pos);

        //adjust velocity
        Vect v = pObj->getVel();
        v.y *= -1;
        v.x = 0;
        pObj->applyForce(pObj->getMass(), v, 1);
    }
}

/*******************************************************************************
 Name:              doCollide
 Description:       Determines if two PhysicalObjects collided
 
 Input:
    a               PhysicalObject*
    b               PhysicalObject*
 ******************************************************************************/
bool PhysicsEngine::doCollide(PhysicalObject *a, PhysicalObject *b)
{
    //check bounding box collision
    return doIntersect(a->getPos(), b->getPos());
}

bool PhysicsEngine::doCollide(CircleObject *a, CircleObject *b)
{
    return doIntersect(((CircleObject*)a)->getCircle(),
                       ((CircleObject*)b)->getCircle());
}

/*******************************************************************************
 Name:              resolveCollision
 Description:       This method determines the type of collision and calls
                    appropriate hanlding methods
 
 Input:
    a               PhysicalObject*
    b               PhysicalObject*
 ******************************************************************************/
void PhysicsEngine::resolveCollision(PhysicalObject* obj, PhysicalObject* obj2)
{
    int sideA, sideB;

    //evaluate side of collision for both objects
    sideA = sideOfCollision(obj, obj2);

    if(sideA)
    {
        //determine side of obj2
        if(sideA - 4 <= 0)  sideB = sideA + 4;
        else                sideB = sideA - 4;

        //react to collision
        handleCollision_Box(obj, obj2, sideB);
        handleCollision_Box(obj2, obj, sideA);
    }
}

/*******************************************************************************
 Name:              resolveCollision
 Description:       This method determines the type of collision and calls
 appropriate hanlding methods
 
 Input:
    a               CircleObject*
    b               CircleObject*
 ******************************************************************************/
void PhysicsEngine::resolveCollision(CircleObject* obj, CircleObject* obj2)
{
    handleCollision(obj, obj2);
    handleCollision(obj2, obj);
}

/*******************************************************************************
 Name:              sideOfCollision
 Description:       This method determines the side of a box collision
 
 Input:
    a               PhysicalObject*
    b               PhysicalObject*
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

    //evaluate initial collision sides
    if(a.y > b.y)               aBottom = false;
    if(a.x > b.x)               aRight  = false;
    if(a.y + a.h < b.y + b.h)   aTop    = false;
    if(a.x + a.w < b.x + b.w)   aLeft   = false;

    //evaluate impossible 3-side collision case
    if(aTop + aBottom + aRight + aLeft == 3)
    {
        if(aTop && aBottom)     aTop = aBottom = false;
        else                    aLeft = aRight = false;
    }

    //eliminate impossible corner cases
    if(aTop + aBottom + aRight + aLeft == 2)
    {
        Vect velA = obj->getVel();
        Vect velB = obj2->getVel();

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
        Vect velA = obj->getVel();
        Vect velB = obj2->getVel();

        double tx, ty;

        if(aTop)            ty = abs(a.y - (b.y + b.h)) / abs(velA.y - velB.y);
        else if(aBottom)    ty = abs((a.y + a.h) - b.y) / abs(velA.y - velB.y);

        if(aLeft)           tx = abs(a.x - (b.x + b.w)) / abs(velA.x - velB.x);
        else if(aRight)     tx = abs((a.x + a.w) - b.x) / abs(velA.x - velB.x);

        if(ty > tx)         aTop = aBottom = false;
        else if(ty < tx)    aLeft = aRight = false;
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
 Name:              handleCollision_Box
 Desription:        This method handles a box collision
 
 Input:
    a               PhysicalObject*
    b               PhysicalObject*
 ******************************************************************************/
void PhysicsEngine::handleCollision_Box(PhysicalObject* obj, PhysicalObject* obj2, int side)
{
    if(side == TOP || side == BOTTOM)
    {
        //adjust position to avoid post-collision problem
        SDL_Rect a = obj2->getPos();
        if(side == TOP) a.y++;
        else a.y--;
        obj2->setPos(a);

        //adjust velocity based on force of collision
        Vect v = obj->getVel();
        v.x = 0;
        obj2->applyForce(obj->getMass(), v, 1);
    }
    else if(side == LEFT || side == RIGHT)
    {
        //adjust position to avoid post-collision problem
        SDL_Rect a = obj2->getPos();
        if(side == LEFT) a.x++;
        else a.x--;
        obj2->setPos(a);

        //adjust velocity based on force of collision
        Vect v = obj->getVel();
        v.y = 0;
        obj2->applyForce(obj->getMass(), v, 0);
    }
    else
    {
        //adjust velocity based on force of collision
        Vect v = obj->getVel();
        obj2->applyForce(obj->getMass(), v, 2);
    }

    //record collision side
    obj2->setCollisionSide(side);
}

/*******************************************************************************
 Name:              handleCollision
 Desription:        This method handles a circle collision
 
 Input:
    a               CircleObject*
    b               CircleObject*
 ******************************************************************************/
void PhysicsEngine::handleCollision(CircleObject* obj, CircleObject* obj2)
{
    Circle a = obj->getCircle();
    Circle b = obj2->getCircle();

    Point i = pointOfIntersection(a, b);
    Vect  l = Vect(i, b.cent);

    double ang1 = l.angle();
    double ang2 = obj->getVel().angle();
    double ang3 = ang2 - ang1;

    if(abs(ang3) <= (M_PI / 2) - .1 && obj->getVel().len()) //.1 accounts for rounding error
    {
        double fa = obj->getVel().len();
        double fm = fa * cos(ang3);
        double fs = fa * sin(ang3);

        Vect m = Vect(fm * cos(ang1), fm * sin(ang1));
        Vect s = Vect(fs * sin(ang1), fs * cos(ang1));  //USED FOR SPIN MAYBE?

        obj2->applyForce(obj->getMass(), m);

        Vect acc = obj->getAcc();
        acc = acc + (m * -1);
        obj->setAcc(acc);
    }
}
