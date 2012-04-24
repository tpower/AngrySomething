/*******************************************************************************
 Filename:                  StateEngine.h
 Classname:                 StateEngine
 
 Description:               This file implements StateEngine. The state engine
                            is responsible for managing the state of the objects
                            in the Room as well as managing the condition of the
                            Room and level.
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
