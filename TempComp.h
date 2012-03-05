/*******************************************************************************
 Filename:                  TempComp.h
 Classname:                 TempComp
 
 Description:               This file declares the TempComp class. It is just
                            used for testing purposes to instantiate a subclass
                            of the abstract class, Component.
 
 Last Modified:            				03.02.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_TempComp_h
#define AngrySomething_TempComp_h

#include "Component.h"
#include <SDL/SDL.h>
#include <fstream>

class TempComp : public Component
{
private:
    int     numData;
    char    *charData;
    
public:
    TempComp();
    TempComp(const TempComp&);
    ~TempComp();
    
    virtual bool    load(fstream& file);
    virtual int     update();
};

#endif
