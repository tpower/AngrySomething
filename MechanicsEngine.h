/*******************************************************************************
 Filename:                  MechanicsEngine.h
 Classname:                 MechanicsEngine
 
 Description:               The MechanicsEngine class handles the game mechanics
                            events within the game.
 ******************************************************************************/

#ifndef MECHANICSENGINE_H
#define MECHANICSENGINE_H

#include <SDL/SDL.h>

#include "Room.h"

class MechanicsEngine
{
    private:
        SDL_Event event;

    public:
        void run(Room& room);
};

#endif
