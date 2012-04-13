#include "Ground.h"

Ground::Ground(const char* file, int x, int y, int vx, int vy, int w, int h)
    :   DrawableObject(file),
        PhysicalObject(vx, vy),
        Object(x, y, w, h)
{

}

Ground::Ground(const Ground& other)
    :   DrawableObject("TestA.bmp"),
        PhysicalObject(other.pos.x, other.pos.y),
        Object(other.pos.x, other.pos.y)
{

}

Ground::~Ground()
{

}

Ground& Ground::operator=(Ground& other)
{
    if(&other != this)
    {

    }

    return *this;
}
