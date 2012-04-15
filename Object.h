/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object

 Description:               This file declares the Object class.
 ******************************************************************************/

#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include <SDL/SDL.h>

class Object
{
    protected:
        SDL_Rect    pos;
        int         state;
        bool        drawable;
        bool        physical;
        bool        mechanical;

    public:
        Object(int x = 0, int y = 0, int w = 0, int h = 0);
        virtual ~Object();

        void            setPos(SDL_Rect p);

        SDL_Rect        getPos();
        int             getState();
        bool            isDrawable();
        bool            isPhysical();
        bool            isMechanical();

        virtual void    run();
};

#endif
