/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object

 Description:               This file declares the Object class. The Object
                            class holds the components that define the objects
                            in the game.

 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include <SDL/SDL.h>
#include <fstream>

#include "Base.h"

class Component;

using namespace std;

class Object : public Base
{
    private:
        Component   **comp;
        int         numComps;

    public:
        Object();
        Object(const Object&);
        ~Object();

        Object      operator=(const Object& other);

        Component*  getComp(int);
        int         getNumComps();

        void        removeCompAt(int);

        bool        load(fstream& file);
        bool        save(fstream& file);
        GameState   update();
};

#endif
