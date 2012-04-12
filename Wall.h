#ifndef WALL_H
#define WALL_H
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MechanicsObject.h"

class Wall : public DrawableObject, public PhysicalObject, public MechanicsObject
{
    private:
        int health;
    public:
        Wall(const char* file, int x, int y, int vx, int vy, int w, int h);
        Wall(const Wall& other);
        ~Wall();

        Wall&     operator=(const Wall& other);

        virtual void    run();
        void            applyForce(int m, vect v, int dir);

};

#endif // WALL_H
