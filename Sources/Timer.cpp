/*******************************************************************************
 Filename:                  Timer.h
 Classname:                 Timer       
 ******************************************************************************/

#include "Timer.h"

/*******************************************************************************
 Name:              Timer
 Description:       Primary constructor
 
 Input:
    t               int roomTime
 ******************************************************************************/
Timer::Timer(int t) : MechanicsObject()
{
    roomTime = t;
    startTime = SDL_GetTicks();

    type = 1;

    activeDraw = false;
    activePhys = false;
    activeMech = true;
    activeCont = false;
}

/*******************************************************************************
 Name:              process
 Description:       This method overrides MechanicsObject::process()
 
 Output:
    returns         Object* to be added to room
 ******************************************************************************/
Object* Timer::process()
{
    if((SDL_GetTicks() - startTime) >= roomTime)
    {
        state = -4;
    }
    return NULL;
}
