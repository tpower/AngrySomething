/*******************************************************************************
 Filename:                  GraphicsEngine.h
 Classname:                 GraphicsEngine

 Description:               This file declares the GraphicsEngine class. The
                            GraphicsEngine class is responsible for output to
                            the screen.
 ******************************************************************************/

#ifndef AngrySomething_GraphicsEngine_h
#define AngrySomething_GraphicsEngine_h

#include <SDL/SDL.h>
#include "DrawableObject.h"
#include "Room.h"

class Room;

class GraphicsEngine
{
    private:
        SDL_Surface*    screen;

    public:
        GraphicsEngine();
        ~GraphicsEngine();

        void            run(Room&);
        void            sortByLayer(vector<DrawableObject*>&);
};

#endif
