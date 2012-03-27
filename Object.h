/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object

 Description:               This file declares the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 ******************************************************************************/
#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include <SDL/SDL.h>
#include <string>
#include <fstream>

#include "Base.h"

using namespace std;

struct vect
{
    double x, y;
};

class Object : public Base
{
    protected:
        SDL_Rect    position;
        vect        vel;
        
    public:
        Object(int, int);
    
        SDL_Rect    getPosition();
        vect        getVel();
        void        setPosition(SDL_Rect p);
        void        setVel(vect v);
    
        void run();
};

#endif
