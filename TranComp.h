/*******************************************************************************
 Filename:                  TranComp.h
 Classname:                 TranComp
 
 Description:               This file declares the TranComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_TranComp_h
#define AngrySomething_TranComp_h

#include "Component.h"
#include <SDL/SDL.h>
#include <fstream>

class TranComp : public Component
{
private:
    
public:
    TranComp();
    TranComp(const TranComp&);
    ~TranComp();
    
    virtual bool    load(fstream& file);
    virtual int     update();
};

#endif
