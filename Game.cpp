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
    int mechState;
    int currentLevel = 0;
    while(running)
    {
        mechState = mech.run(room);
        phys.run(room);
        grph.run(room);
        if(mechState == -2)
            currentLevel++;
        switch(mechState)
        {
            //Reset the level
            case -5:
                if(!room.load(decideLevel(currentLevel).c_str()))
                    running = room.load("TitleScreen.gel");
                break;
            //TitleScreen
            case -4:
                running = room.load("TitleScreen.gel");
                break;
            //Level Select
            case -3:
                running = room.load("LevelSelect.gel");
                break;
            //You beat the previous level, move to the next level
            case -2:
                if(!room.load(decideLevel(currentLevel).c_str()))
                    running = room.load("TitleScreen.gel");
                break;
            // You Lose. Exit the program
            case -1:
                running = false;
                break;
            // Load whichever level you like
            case 1:
                running = room.load("Level1.gel");
                currentLevel = 1;
                break;
            case 2:
                running = room.load("Level2.gel");
                currentLevel = 2;
                break;
            case 3:
                running = room.load("Level3.gel");
                currentLevel = 3;
                break;
        }
        SDL_Delay(15);
    }

    return 0;
}

string Game::decideLevel(int i)
{
    char buffer[1];
    string s = "Level";
    s += sprintf(buffer,"%d",i);
    s += ".gel";
    return s;
}
