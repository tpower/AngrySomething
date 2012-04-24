/*******************************************************************************
 Filename:                  Timer.h
 Classname:                 Timer
 
 Description:               
 ******************************************************************************/

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "MechanicsObject.h"

class Timer : public MechanicsObject
{
    private:
        int startTime;
        int roomTime;
    
    public:
        Timer(int t);

        Object*         process();
};

#endif
