
#ifndef AngrySomething_Game_h
#define AngrySomething_Game_h

#include <SDL/SDL.h>
#include <string>

#include "Base.h"
#include "Room.h"
#include "View.h"

using namespace std;

// Game Controller
class Game : public Base
{
    private:
        Room room;
        View view;
    
        bool init();
        void handleEvent(SDL_Event* event);
    
    public:
        Game();
        Game(const Game&);
        ~Game();
        
        // progress through the game loop
        int run();
        
        // called to end the game
        void stop();
};

#endif
