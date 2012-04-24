/*******************************************************************************
 Filename:                  StateEngine.h
 Classname:                 StateEngine
 
 Description:               
 ******************************************************************************/

#ifndef STATEENGINE_H
#define STATEENGINE_H

#include <string>

#include "MechanicsEngine.h"
#include "Object.h"
#include "MechanicsObject.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Sling.h"

class StateEngine
{
    public:
        bool run(Room& room);
        string  decideLevel(int i);
};
#endif
