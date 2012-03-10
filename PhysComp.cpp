/*******************************************************************************
 Filename:                  PhysComp.cpp
 Classname:                 PhysComp
 
 Description:               This file defines the PhysComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "PhysComp.h"

/*******************************************************************************
 Name:              PhysComp
 Description:       Default constructor for PhysComp class
 ******************************************************************************/
PhysComp::PhysComp() : Component(PHYSCOMP)
{
    
}

/*******************************************************************************
 Name:              PhysComp
 Description:       Copy constructor for PhysComp class
 ******************************************************************************/
PhysComp::PhysComp(const PhysComp& other) : Component(PHYSCOMP)
{
    
}

/*******************************************************************************
 Name:              ~PhysComp
 Description:       Destructor for PhysComp class
 ******************************************************************************/
PhysComp::~PhysComp()
{
    
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the PhysComp
 
 Input:
    file            fstream& from which to load the PhysComp
 
 Output:
    returns         bool value of whether the PhysComp loaded correctly
 ******************************************************************************/
bool PhysComp::load(fstream& file)
{
    if(!file) return false;
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the PhysComp
 ******************************************************************************/
int PhysComp::update()
{
    return 0;
}


