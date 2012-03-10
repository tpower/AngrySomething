/*******************************************************************************
 Filename:                  GrphComp.h
 Classname:                 GrphComp
 
 Description:               This file declares the GrphComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_GrphComp_h
#define AngrySomething_GrphComp_h

#include "Component.h"
#include <SDL/SDL.h>
#include <fstream>

class GrphComp : public Component
{
private:
    
public:
    GrphComp();
    GrphComp(const GrphComp&);
    ~GrphComp();
    
    virtual bool    load(fstream& file);
    virtual int     update();
};

#endif
