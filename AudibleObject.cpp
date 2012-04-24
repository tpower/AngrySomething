/*******************************************************************************
 Filename:                  AudibleObject.cpp
 Classname:                 AudibleObject
 
 Description:               The AudibleObject class is a subclass of Object that
                            has impementation to play sound effects.
 ******************************************************************************/

#include "AudibleObject.h"

AudibleObject::AudibleObject(string file)
{
    noise = Mix_LoadWAV( "noise.wav" );
    if(!noise)
    {
        exit(-1);
    }
    
    audible = true;
}

AudibleObject::~AudibleObject()
{
    Mix_FreeChunk(noise);
}

bool AudibleObject::wantsToBeNoisy()
{
    return noisy;
}

void AudibleObject::shouldBeNoisy(bool n)
{
    noisy = true;
}

Mix_Chunk* AudibleObject::getNoise()
{
    noisy = false;
    return noise;
}

