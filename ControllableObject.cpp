/*******************************************************************************
 Filename:                  ControllableObject.h
 Classname:                 ControllableObject
 
 Description:               The ControllableObject class is a subclass of Object
                            that can receive user input.
 ******************************************************************************/

#include "ControllableObject.h"

ControllableObject::ControllableObject()
{
    controllable = true;
}

void ControllableObject::handle(SDL_Event event)
{
    
}
