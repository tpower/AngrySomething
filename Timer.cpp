/*******************************************************************************
 Filename:                  Timer.h
 Classname:                 Timer
 
 Description:               
 ******************************************************************************/

#include "Timer.h"

Timer::Timer(int t)
    :   MechanicsObject()
{
    roomTime = t;
    startTime = SDL_GetTicks();

    type = 1;

    activeDraw = false;
    activePhys = false;
    activeMech = true;
    activeCont = false;
}

Object* Timer::process()
{
    if((SDL_GetTicks() - startTime) >= roomTime)
    {
        state = -4;
    }
    return NULL;
}
