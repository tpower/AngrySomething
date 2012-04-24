/*******************************************************************************
 Filename:                  StateEngine.h
 Classname:                 StateEngine
 
 Description:               
 ******************************************************************************/

#ifndef STATEENGINE_H
#define STATEENGINE_H

#include <string>

#include "Room.h"

class StateEngine
{
    public:
        bool    run(Room& room);
        string  decideLevel(int i);
};

#endif
