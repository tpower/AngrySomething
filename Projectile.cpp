/*******************************************************************************
 Filename:                  Projectile.h
 Classname:                 Projectile
 
 Description:               This file defines the Projectile class.
 ******************************************************************************/

#include "Projectile.h"

Projectile::Projectile(const char* file, int x, int y, int vx, int vy)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, 50, 50)
{
    
}

Projectile::Projectile(const Projectile& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        Object(other.pos.x, other.pos.y)
{
    
}

Projectile::~Projectile()
{
    
}

Projectile& Projectile::operator=(const Projectile& other)
{
    if(&other != this)
    {
        
    }
    
    return *this;
}

//void Projectile::draw(SDL_Surface* screen)
//{
//    
//}

void Projectile::run()
{
    move();
    
    //TODO: destroy object when vel drops below certain threshold
}

//void Projectile::applyForce(int m, vect v)
//{
//    
//}

