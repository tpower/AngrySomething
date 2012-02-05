/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object
 
 Description:               This file declares the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include <string>

#include "Base.h"
#include "Component.h"

using namespace std;

class Object : public Base
{
    private:
        Component *comp;
    
    public:
        Object();
        Object(Object&);
        ~Object();
};

#endif
