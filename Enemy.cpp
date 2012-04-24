/*******************************************************************************
 Filename:                  Enemy.h
 Classname:                 Enemy
 
 Description:               The Enemy class is an object that serves as the
                            primary target in gameplay.
 ******************************************************************************/

#include <cmath>

#include "Enemy.h"

int Enemy::numEnemies = 0;

Enemy::Enemy(const char* file, int x, int y, int vx, int vy)
    :   Object(x, y, 20, 20),
        DrawableObject(file, 2),
        PhysicalObject(vx, vy)
{
    health = 100;
    numEnemies++;

    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}

Enemy::Enemy(const Enemy& other)
    :   Object(other.pos.x, other.pos.y),
        DrawableObject("TestA.bmp", 2),
        PhysicalObject(other.pos.x, other.pos.y)
{
    numEnemies++;
}

Enemy::~Enemy()
{
    numEnemies--;
    adjustScore(100);
}

void Enemy::run()
{
    move();

    if(health <= 0)
    {
        state = -1;
    }
}

void Enemy::applyForce(int m, Vect v, int dir)
{
    PhysicalObject::applyForce(m, v, dir);

    if(pow((pow(v.y,2.0) + pow(v.x, 2.0)), .5) > 4)
    {
        health -= 100;
    }
}

void Enemy::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

void Enemy::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void Enemy::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}
