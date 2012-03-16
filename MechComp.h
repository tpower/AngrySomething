/*******************************************************************************
 Filename:                  MechComp.h
 Classname:                 MechComp

 Description:               This file declares the MechComp class.

 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_MechComp_h
#define AngrySomething_MechComp_h

#include "Component.h"
#include <SDL/SDL.h>
#include <fstream>

class MechComp : public Component
{
    private:
        
    public:
        MechComp();
        MechComp(const MechComp&);
        ~MechComp();
        
        MechComp            operator=(const MechComp& other);
        
        virtual bool        load(fstream& file);
        virtual bool        save(fstream& file);
        virtual GameState   update();
};

#endif
