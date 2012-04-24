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
        bool        controllable;
        bool        audible;
        bool        activeDraw;
        bool        activePhys;
        bool        activeMech;
        bool        activeCont;
        int         type;   //1 = level, 2 = Utility

    public:
        Object(int x = 0, int y = 0, int w = 0, int h = 0);
        virtual ~Object();

        Object          operator=(const Object& other);
        void            setPos(SDL_Rect p);

        virtual int     check();

        SDL_Rect        getPos();
        int             getState();
        int             getType();
        bool            isDrawable();
        bool            isPhysical();
        bool            isMechanical();
        bool            isControllable();
        bool            isAudible();
        bool            getActiveDraw() {return activeDraw;}
        bool            getActivePhys() {return activePhys;}
        bool            getActiveMech() {return activeMech;}
        bool            getActiveCont() {return activeCont;}
//        void            setActiveDraw(bool b) {activeDraw = b;}
//        void            setActivePhys(bool b) {activePhys = b;}
//        void            setActiveMech(bool b) {activeMech = b;}
//        void            setActiveCont(bool b) {activeCont = b;}
        virtual void    pause();
        virtual void    unpause();

        virtual void    run();
};

#endif
