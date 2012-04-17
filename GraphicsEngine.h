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

class Room;

class GraphicsEngine
{
    private:
        SDL_Surface*    screen;
        SDL_Surface*    background;
            
    public:
        GraphicsEngine();
        ~GraphicsEngine();
    
        void            run(Room&);
};

#endif
