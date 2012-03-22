/*******************************************************************************
 Filename:                  PhysComp.h
 Classname:                 PhysComp

 Description:               This file declares the PhysComp class.

 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_PhysComp_h
#define AngrySomething_PhysComp_h

#include <SDL/SDL.h>
#include <fstream>

#include "Component.h"

struct vect
{
    int x,
        y;
};

class PhysComp : public Component
{
    private:
        vect vel;
        vect acc;
        
    public:
        PhysComp();
        PhysComp(const PhysComp&);
        ~PhysComp();
        
        PhysComp            operator=(const PhysComp& other);
        
        virtual bool        load(fstream& file);
        virtual bool        save(fstream& file);
        virtual GameState   update();
};

#endif
