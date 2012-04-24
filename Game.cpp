/*******************************************************************************
 Filename:                  Game.h
 Classname:                 Game
 
 Description:               The Game class is in charge of running the game loop
                            and handling communication between engines within
                            the game.
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
    running = room.load("IntroLevel.gel");
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
        audi.run(room);
        SDL_Delay(5);
    }

    return 0;
}

