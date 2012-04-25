/*******************************************************************************
 Filename:                  Enemy.h
 Classname:                 Enemy
 
 Description:               The Enemy class is an object that serves as the
                            primary target in gameplay.
 ******************************************************************************/

#ifndef PIG_H
#define PIG_H

#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MechanicsObject.h"

class Enemy : public DrawableObject, public PhysicalObject, public MechanicsObject
{
    private:
        int health;
        static int numEnemies;

    public:
        Enemy(const char* file, int x, int y, int vx, int vy);
        ~Enemy();

        virtual void    run();
        void            applyForce(int m, Vect v, int dir);
        static int      getNumEnemies() {return numEnemies;}
        void            draw(SDL_Surface*);
        void            pause();
        void            unpause();
};

#endif
