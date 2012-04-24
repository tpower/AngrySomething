/*******************************************************************************
 Filename:                  AudioEngine.cpp
 Classname:                 AudioEngine
 
 Description:               
 ******************************************************************************/

#include "AudioEngine.h"
#include "AudibleObject.h"

/*******************************************************************************
 Name:              AudioEngine
 Description:       Default constructor
 ******************************************************************************/
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

/*******************************************************************************
 Name:              AudioEngine
 Description:       Destructor
 ******************************************************************************/
AudioEngine::~AudioEngine()
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}

/*******************************************************************************
 Name:              run
 Description:       This method plays sound effects of every AudibleObject in
                    the room
 
 Input:
    room            Room& that contains AudibleObjects
 ******************************************************************************/
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