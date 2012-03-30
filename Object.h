/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object

 Description:               This file declares the Object class.
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
        Object(const Object&);
        ~Object();

        Object      operator=(const Object& other);
        
        void        setPos(SDL_Rect p);
    
        SDL_Rect    getPos();
    
        void        run();
};

#endif
