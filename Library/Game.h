/*******************************************************************************
 Filename:                  Game.h
 Classname:                 Game

 Description:               The Game class is in charge of running the game loop
                            and handling communication between engines within
                            the game.
 ******************************************************************************/

#ifndef AngrySomething_Game_h
#define AngrySomething_Game_h

#include <SDL/SDL.h>

#include "Room.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "MechanicsEngine.h"
#include "StateEngine.h"
#include "ControlEngine.h"
#include "AudioEngine.h"

class Game
{
    private:
        Room            room;
        StateEngine     state;
        GraphicsEngine  grph;
        PhysicsEngine   phys;
        MechanicsEngine mech;
        ControlEngine   control;
        AudioEngine     audi;
        bool            running;

    public:
        Game();

        void    init();
        int     run();
};

#endif
