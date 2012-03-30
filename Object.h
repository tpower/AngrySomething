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

enum ObjType
{
    OBJECT              = 1,
    DRAWABLE_OBJECT     = 2,
    PHYSICAL_OBJECT     = 3,
    CONTROLLABLE_OBJECT = 4
};

class Object
{
    protected:
        ObjType     type;
        SDL_Rect    pos;
        
    public:
        Object(int x = 0, int y = 0);
        Object(const Object&);
        ~Object();

        Object      operator=(const Object& other);
        
        void        setType(ObjType type);
        void        setPos(SDL_Rect p);
    
        ObjType     getType();
        SDL_Rect    getPos();
    
        void        run();
};

#endif
