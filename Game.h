/*******************************************************************************
 Filename:                  Game.h
 Classname:                 Game

 Description:               This file declares the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Physics and Graphics Engines.
 ******************************************************************************/

#ifndef AngrySomething_Game_h
#define AngrySomething_Game_h

#include <SDL/SDL.h>

#include "Room.h"
#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "MechanicsEngine.h"

class Game
{
    private:
        Room            room;
        GraphicsEngine  grph;
        PhysicsEngine   phys;
        MechanicsEngine mech;
        bool            running;

    public:
        Game();
        Game(const Game&);
        ~Game();

        Game    operator=(const Game& other);

        void    init();
        int     run();
        string  decideLevel(int i);
};

#endif
