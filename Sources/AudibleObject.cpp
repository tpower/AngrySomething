/*******************************************************************************
 Filename:                  AudibleObject.cpp
 Classname:                 AudibleObject
 
 Description:               The AudibleObject class is a subclass of Object that
                            has impementation to play sound effects.
 ******************************************************************************/

#include "AudibleObject.h"

/*******************************************************************************
 Name:              AudibleObject
 Description:       Primary constructor
 
 Input:
    file            string filepath of soundbite
 ******************************************************************************/
AudibleObject::AudibleObject(string file)
{
    noise = Mix_LoadWAV(file.c_str());
    if(!noise)
    {
        exit(-1);
    }
    
    audible = true;
}

/*******************************************************************************
 Name:              ~AudibleObject
 Description:       Destructor
 ******************************************************************************/
AudibleObject::~AudibleObject()
{
    Mix_FreeChunk(noise);
}

/*******************************************************************************
 ACCESSORS
 Name:              wantsToBeNoisy, shouldBeNoisy, getNoise
 ******************************************************************************/
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

