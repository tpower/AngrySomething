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
    int x, y;
};

class Object
{
    private:
        SDL_Rect    pos;
        
    public:
        Object(int, int);
        Object(const Object&);
        ~Object();

        Object      operator=(const Object& other);
    
        void        setPos(SDL_Rect p);
    
        SDL_Rect    getPos();
};

#endif
