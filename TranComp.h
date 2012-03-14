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
        SDL_Rect    pos;    //bounding box
        
    public:
        TranComp();
        TranComp(const TranComp&);
        ~TranComp();
        
        TranComp        operator=(const TranComp& other);
        
        SDL_Rect        getPos();
        
        virtual bool    load(fstream& file);
        virtual bool    save(fstream& file);
        virtual int     update();
};

#endif
