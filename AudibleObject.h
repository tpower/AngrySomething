/*******************************************************************************
 Filename:                  AudibleObject.h
 Classname:                 AudibleObject
 
 Description:               The AudibleObject class is a subclass of Object that
                            has impementation to play sound effects.
 ******************************************************************************/

#ifndef AngrySomething_AudibleObject_h
#define AngrySomething_AudibleObject_h

#include <SDL/SDL.h>
#include <SDL_mixer/SDL_mixer.h>
#include <string>

#include "Object.h"

using namespace std;

class AudibleObject : virtual public Object
{
    private:
        Mix_Chunk   *noise;
        bool        noisy;
    
    public:
        AudibleObject(string file);
        ~AudibleObject();
    
        void shouldBeNoisy(bool n = true);
        bool wantsToBeNoisy();
        Mix_Chunk* getNoise();
};

#endif
