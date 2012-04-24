/*******************************************************************************
 Filename:                  DestructableWall.h
 Classname:                 DestructableWall
 
 Description:               The DestructableWall class is a subclass of Wall
                            that can be destroyed.
 ******************************************************************************/

#ifndef DESTRUCTABLEWALL_H_INCLUDED
#define DESTRUCTABLEWALL_H_INCLUDED

#include "Wall.h"

class DestructableWall : public Wall
{
    public:
        DestructableWall(const char* file, int x, int y, int vx, int vy, int w,
                         int h);
        void    run();
};

#endif
