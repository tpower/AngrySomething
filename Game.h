/*******************************************************************************
 Filename:                  Game.h
 Classname:                 Game

 Description:               This file declares the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Room and the View
 ******************************************************************************/

#ifndef AngrySomething_Game_h
#define AngrySomething_Game_h

#include <fstream>
#include <SDL/SDL.h>
#include "Room.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"

using namespace std;

class Game
{
    private:
        Room room;
        GraphicsEngine grph;
        PhysicsEngine phys;
        bool running;

    public:
        Game();

        void    init();
        int     run();
};

#endif
