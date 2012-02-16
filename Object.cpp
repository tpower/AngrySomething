/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object
 
 Description:               This file defines the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "Object.h"

/*******************************************************************************
 Name:              Object
 Description:       Default constructor for Object class
 ******************************************************************************/
Object::Object() : Base("object")
{
    
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(Object&) : Base("object")
{
    
}

/*******************************************************************************
 Name:              Object
 Description:       Destructor for Object class
 ******************************************************************************/
Object::~Object()
{
    if(comp) delete [] comp;
}