/*******************************************************************************
 Filename:                  Game.h
 Classname:                 Game
 
 Description:               This file declares the Game class. This class will
                            be the controller for the game. It is in charge of
                            running the game loop and handling communication
                            between the Room and the View
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Game_h
#define AngrySomething_Game_h

#include <SDL/SDL.h>
#include <string>

#include "Base.h"
#include "Room.h"
#include "View.h"

using namespace std;

class Game : public Base
{
    private:
        Room *room;
        View *view;
        bool running;
    
    public:
        Game();
        Game(const Game&);
        ~Game();
    
        int  run();
        void stop();
        bool init();
        void handleEvent(SDL_Event* event);
};

#endif
