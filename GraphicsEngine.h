#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <SDL/SDL.h>

#include "Room.h"

class GraphicsEngine
{
    private:
        SDL_Surface* screen;
    
    public:
        GraphicsEngine();
        ~GraphicsEngine();
        virtual void run(Room&);
};


#endif
