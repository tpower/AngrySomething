/*******************************************************************************
 Filename:                  ControllableObject.h
 Classname:                 ControllableObject
 
 Description:               The ControllableObject class is a subclass of Object
                            that can receive user input.
 ******************************************************************************/

#include "ControllableObject.h"

/*******************************************************************************
 Name:              ControllableObject
 Description:       Default constructor
 ******************************************************************************/
ControllableObject::ControllableObject()
{
    controllable = true;
}

/*******************************************************************************
 Name:              handle
 Description:       This method handles user input
 
 Input:
    e               SDL_Event to be handled
 ******************************************************************************/
void ControllableObject::handle(SDL_Event event)
{
    
}
