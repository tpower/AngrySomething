/*******************************************************************************
 Filename:                  GraphicsEngine.h
 Classname:                 GraphicsEngine

 Description:               The GraphicsEngine class handles drawing objects to
                            the screen.
 ******************************************************************************/

#ifndef AngrySomething_GraphicsEngine_h
#define AngrySomething_GraphicsEngine_h

#include <SDL/SDL.h>

#include "DrawableObject.h"
#include "Room.h"

class GraphicsEngine
{
    private:
        SDL_Surface*    screen;

    public:
        GraphicsEngine();
        ~GraphicsEngine();

        void    run(Room&);
        void    sortByLayer(vector<DrawableObject*>&);
};

#endif
