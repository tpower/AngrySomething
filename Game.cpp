/*******************************************************************************
 Filename:                  Game.cpp
 Classname:                 Game

 Description:               This file defines the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Physics and Graphics Engines.
 ******************************************************************************/

#include <cstdlib>
#include "Game.h"
using namespace std;

/*******************************************************************************
 Name:              Game
 Description:       Default constructor for Game class
 ******************************************************************************/
Game::Game()
{
    running = false;
}

/*******************************************************************************
 Name:              init
 Description:       This method handles any initialization involved before the
                    run loop begins
 ******************************************************************************/
void Game::init()
{
    running = room.load("TitleScreen.gel");
    room.setRoomType(Utility);
}

/*******************************************************************************
 Name:              run
 Description:       This method starts the game and controls the game loop

 Output:
    returns         int value representing the exit state of the game
 ******************************************************************************/
int Game::run()
{
    while(running)
    {
        running = state.run(room);
        control.run(room);
        mech.run(room);
        phys.run(room);
        grph.run(room);
        SDL_Delay(5);
    }

    return 0;
}

