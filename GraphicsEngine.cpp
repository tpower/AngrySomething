#include "GraphicsEngine.h"
#include <iostream>

GraphicsEngine::GraphicsEngine()
{
    screen = SDL_SetVideoMode(640,480,32, SDL_SWSURFACE | SDL_DOUBLEBUF);

    if(!screen)
    {
        cout << "Error: Problem loading screen!" << endl;
    }
}

GraphicsEngine::~GraphicsEngine()
{
    SDL_FreeSurface(screen);
}

void GraphicsEngine::run(Room& room)
{
    for(int i = 0; i < ; i++)
    {
        room.getObjectAt(i)->draw(screen);
    }

    SDL_Flip(screen);
}
