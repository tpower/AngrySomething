/*******************************************************************************
 Filename:                  Game.cpp
 Classname:                 Game

 Description:               This file defines the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Physics and Graphics Engines.
 ******************************************************************************/

#include "Game.h"

/*******************************************************************************
 Name:              Game
 Description:       Default constructor for Game class
 ******************************************************************************/
Game::Game()
{
    running = false;
}

/*******************************************************************************
 Name:              Game
 Description:       Copy constructor for Game class

 Input:
    other           Game object to be copied
 ******************************************************************************/
Game::Game(const Game& other)
{
    
}

/*******************************************************************************
 Name:              ~Game
 Description:       Destructor for Game class
 ******************************************************************************/
Game::~Game()
{
    
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Game class

 Input:
    other           const Game&
 ******************************************************************************/
Game Game::operator=(const Game& other)
{
    if(&other != this)
    {
        
    }

    return *this;
}

/*******************************************************************************
 Name:              init
 Description:       This method handles any initialization involved before the
                    run loop begins
 ******************************************************************************/
void Game::init()
{
    running = room.load();
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
        mech.run(room);
        phys.run(room);
        grph.run(room);
    }

    return 0;
}

