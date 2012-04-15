
#ifndef AngrySomething_CircleObject_h
#define AngrySomething_CircleObject_h

#include "PhysicalObject.h"
#include "Geometry.h"

class CircleObject : public PhysicalObject
{
protected:
    Circle circ;
    
public:
    CircleObject(int vx = 0, int vy = 0);
    
    Circle getCircle();
    
    virtual void    run();
    virtual void    applyForce(int m, Vect v);
};

#endif
