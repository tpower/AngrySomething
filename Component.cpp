/*******************************************************************************
 Filename:                  Component.cpp
 Classname:                 Component
 
 Description:               This file declares the Component class. The
                            Component class is an abstract class that is used as
                            a template for extensions of this class. The role of
                            a Component object is to define a characteristic of
                            an object that contains it.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include <iostream>

#include "Component.h"

using namespace std;

/*******************************************************************************
 Name:              Component
 Description:       Primary constructor for Component class
 ******************************************************************************/
Component::Component(int type) : Base(type)
{
    
}

/*******************************************************************************
 Name:              Component
 Description:       Copy constructor for Component class
 ******************************************************************************/
Component::Component(const Component& other) : Base(other.getType())
{
    
}
