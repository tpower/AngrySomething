#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
#include "DrawableObject.h"
#include <vector>
#include "Room.h"
#include <SDL/SDL.h>

class GraphicsEngine
{
    private:
        SDL_Surface* screen;
    public:
        GraphicsEngine();
        ~GraphicsEngine();
        virtual void drawAll(Room&);
};


#endif // GRAPHICSENGINE
