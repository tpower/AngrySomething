/*******************************************************************************
 Filename:                  Component.h
 Classname:                 Component

 Description:               This file declares the Component class. The
                            Component class is an abstract class that is used as
                            a template for extensions of this class. The role of
                            a Component object is to define a characteristic of
                            an object that contains it.

 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Component_h
#define AngrySomething_Component_h

#include <SDL/SDL.h>
#include <fstream>

#include "Base.h"

class Component : public Base
{
    private:
        
    public:
        Component(int type);
        Component(const Component&);
        
        virtual bool        load(fstream& file) = 0;
        virtual bool        save(fstream& file) = 0;
        virtual GameState   update() = 0;
};

#endif
