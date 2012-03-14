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

//Parent class
#include "Base.h"

//Components
#include "Component.h"
#include "MechComp.h"
#include "TranComp.h"
#include "PhysComp.h"
#include "GrphComp.h"

//Other libraries
#include <SDL/SDL.h>
#include <fstream>

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
