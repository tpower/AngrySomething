/*******************************************************************************
 Filename:                  AudioEngine.h
 Classname:                 AudioEngine
 
 Description:               
 ******************************************************************************/

#ifndef AngrySomething_AudioEngine_h
#define AngrySomething_AudioEngine_h

#include <SDL/SDL.h>
#include <SDL_mixer/SDL_mixer.h>

#include "Room.h"

class AudioEngine
{
    private:
        Mix_Music *music;
        
    public:
        AudioEngine();
        ~AudioEngine();
    
        void run(Room& room);
};

#endif
