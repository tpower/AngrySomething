/*******************************************************************************
 Filename:                  AudioEngine.cpp
 Classname:                 AudioEngine
 
 Description:               
 ******************************************************************************/

#include "AudioEngine.h"

AudioEngine::AudioEngine()
{
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        exit(-1);
    }
    
    music = Mix_LoadMUS("music.wav");
    if(music == NULL)
    {
        exit(-1);
    }
    
    if(Mix_PlayMusic( music, -1 ) == -1)
    {
        exit(-1);
    }
}

AudioEngine::~AudioEngine()
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

void AudioEngine::run(Room& room)
{
    for(int i = 0; i < room.getNumObjects(); i++)
    {
        if(room.getObjectAt(i)->isAudible())
        {
            AudibleObject* ao = dynamic_cast<AudibleObject*>(room.getObjectAt(i));
            if(ao->wantsToBeNoisy())
            {
                Mix_Chunk* noise = ao->getNoise();
                Mix_PlayChannel(-1, noise, 0);
            }
        }
    }
}