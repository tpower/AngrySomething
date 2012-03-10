/*******************************************************************************
 Filename:                  MechComp.cpp
 Classname:                 MechComp
 
 Description:               This file defines the MechComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "MechComp.h"

/*******************************************************************************
 Name:              MechComp
 Description:       Default constructor for MechComp class
 ******************************************************************************/
MechComp::MechComp() : Component()
{
    
}

/*******************************************************************************
 Name:              MechComp
 Description:       Copy constructor for MechComp class
 ******************************************************************************/
MechComp::MechComp(const MechComp& other)
{
    
}

/*******************************************************************************
 Name:              ~MechComp
 Description:       Destructor for MechComp class
 ******************************************************************************/
MechComp::~MechComp()
{
    
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the MechComp
 
 Input:
    file            fstream& from which to load the MechComp
 
 Output:
    returns         bool value of whether the MechComp loaded correctly
 ******************************************************************************/
bool MechComp::load(fstream& file)
{
    if(!file) return false;
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the MechComp
 ******************************************************************************/
int MechComp::update()
{
    return 0;
}

