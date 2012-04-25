/*******************************************************************************
 Filename:                  Enemy.h
 Classname:                 Enemy
 
 Description:               The Enemy class is an object that serves as the
                            primary target in gameplay.
 ******************************************************************************/

#include <cmath>

#include "Enemy.h"

int Enemy::numEnemies = 0;

/*******************************************************************************
 Name:              Enemy
 Description:       Primary constructor
 
 Input:
    file            char* filepath for image file
    x               int horizontal position
    y               int vertical position
    vx              int horizontal velocity
    vy              int vertical velocity
 ******************************************************************************/
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

/*******************************************************************************
 Name:              ~Enemy
 Description:       Destructor
 ******************************************************************************/
Enemy::~Enemy()
{
    numEnemies--;
    adjustScore(100);
}

/*******************************************************************************
 Name:              run
 Description:       This method overrides PhysicalObject::run()
 ******************************************************************************/
void Enemy::run()
{
    move();

    if(health <= 0)
    {
        state = -1;
    }
}

/*******************************************************************************
 Name:              applyForce
 Description:       This method overrides PhysicalObject::applyForce()
 
 Input:
    m               int mass of colliding Object
    v               Vect velocity of colliding Object
    dir             int direction of collision
 ******************************************************************************/
void Enemy::applyForce(int m, Vect v, int dir)
{
    PhysicalObject::applyForce(m, v, dir);

    if(pow((pow(v.y,2.0) + pow(v.x, 2.0)), .5) > 4)
    {
        health -= 100;
    }
    else if(pow((pow(v.y,2.0) + pow(v.x, 2.0)), .5) > 3)
    {
        health -= 25;
    }
}

/*******************************************************************************
 Name:              draw
 Description:       This method overrides DrawableObject::draw()
 
 Input:
    s               SDL_Surface* to be drawn to
 ******************************************************************************/
void Enemy::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the Enemy
 ******************************************************************************/
void Enemy::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the Enemy if it is paused
 ******************************************************************************/
void Enemy::unpause()
{
    activeDraw = true;
    activePhys = true;
    activeMech = false;
    activeCont = false;
}
