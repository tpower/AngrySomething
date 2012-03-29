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

struct vect
{
    double x, y;
};

class Object
{
    protected:
        SDL_Rect    pos;
        
    public:
        Object(int, int);
    
        SDL_Rect    getPos();
        void        setPos(SDL_Rect p);
    
        void        run();
};

#endif
