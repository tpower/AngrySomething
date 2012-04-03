/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object

 Description:               This file declares the Object class.
 ******************************************************************************/
#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h
#include <SDL/SDL.h>
#include <iostream>

using namespace std;

enum ObjType
{
    OBJECT              = 1,
    DRAWABLE_OBJECT     = 2,
    PHYSICAL_OBJECT     = 3,
    CONTROLLABLE_OBJECT = 4,
<<<<<<< HEAD
    TEST_OBJECT         = 5
};

struct vect
{
    int xvel;
    int yvel;
=======
    MULTI_OBJECT        = 5
>>>>>>> upstream/TylerBranch
};

class Object
{
    protected:
        ObjType     type;
        SDL_Rect    pos;
        vect        vec;
        SDL_Surface* image;
        bool grabbed;

    public:
        Object(const char* file, int x, int y);
        Object(const Object&);
        ~Object();

<<<<<<< HEAD
        Object      operator=(const Object& other);

        void        update(SDL_Event);
        void        draw(SDL_Surface*);
        void        move();

        vect        getVect();

        void        setType(ObjType type);
        void        setPos(SDL_Rect p);
        void        setVect(vect v);

        ObjType     getType();
        SDL_Rect    getPos();
=======
        Object          operator=(const Object& other);
        
        void            setType(ObjType type);
        void            setPos(SDL_Rect p);
    
        ObjType         getType();
        SDL_Rect        getPos();
    
        virtual void    run();
>>>>>>> upstream/TylerBranch
};

#endif
