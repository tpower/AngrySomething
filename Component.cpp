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

#include "Component.h"
#include <iostream>

using namespace std;

/*******************************************************************************
 Name:              Component
 Description:       Default constructor for Component class
 ******************************************************************************/
Component::Component() : Base("component")
{
    
}

/*******************************************************************************
 Name:              Component
 Description:       Copy constructor for Component class
 ******************************************************************************/
Component::Component(const Component& other) : Base("component")
{
    
}

/*******************************************************************************
 Name:              ~Component
 Description:       Destructor for Component class
 ******************************************************************************/
Component::~Component()
{
    
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the component
 
 Output:
    returns         bool value of whether the component loaded correctly
 ******************************************************************************/
bool Component::load()
{
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the Component
 ******************************************************************************/
int Component::update()
{
    return 0;
}


