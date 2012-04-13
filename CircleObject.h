
#ifndef AngrySomething_CircleObject_h
#define AngrySomething_CircleObject_h

#include "PhysicalObject.h"
#include "Geometry.h"

class CircleObject : public PhysicalObject
{
protected:
    
public:
    CircleObject(int x = 0, int y = 0);
    
    virtual void    run();
    virtual void    applyForce(int m, Vect v, int dir = 2);
};

#endif
