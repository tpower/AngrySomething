
#include <SDL/SDL.h>
#include "Game.h"

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        exit(-1);
    }
    
    Game game;
    
    game.init();
    
    return game.run();
}