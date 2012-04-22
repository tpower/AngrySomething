#ifndef GROUND_H_INCLUDED
#define GROUND_H_INCLUDED
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MechanicsObject.h"

class Ground : public DrawableObject, public PhysicalObject, public MechanicsObject
{
    public:
        Ground(const char* file, int x, int y, int vx, int vy, int w, int h);
        Ground(const Ground& other);
        ~Ground();

        Ground& operator=(Ground& other);

        void applyForce(int m, Vect v, int dir);
};

#endif // GROUND_H_INCLUDED
