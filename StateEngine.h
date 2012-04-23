#ifndef STATEENGINE_H
#define STATEENGINE_H
#include "MechanicsEngine.h"
#include "Object.h"
#include "MechanicsObject.h"
#include "Pig.h"
#include "Projectile.h"
#include "Sling.h"
#include <string>

class StateEngine
{
    public:
        bool run(Room& room);
        string  decideLevel(int i);
};
#endif // STATEENGINE_H
