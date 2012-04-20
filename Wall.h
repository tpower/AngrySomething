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

        void            run();
        void            applyForce(int m, Vect v, int dir);
        void            draw(SDL_Surface* screen);
};

#endif // WALL_H
