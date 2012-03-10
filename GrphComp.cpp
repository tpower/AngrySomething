/*******************************************************************************
 Filename:                  GrphComp.cpp
 Classname:                 GrphComp
 
 Description:               This file defines the GrphComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "GrphComp.h"

/*******************************************************************************
 Name:              GrphComp
 Description:       Default constructor for GrphComp class
 ******************************************************************************/
GrphComp::GrphComp() : Component(GRPHCOMP)
{
    
}

/*******************************************************************************
 Name:              GrphComp
 Description:       Copy constructor for GrphComp class
 ******************************************************************************/
GrphComp::GrphComp(const GrphComp& other) : Component(GRPHCOMP)
{
    
}

/*******************************************************************************
 Name:              ~GrphComp
 Description:       Destructor for GrphComp class
 ******************************************************************************/
GrphComp::~GrphComp()
{
    
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the GrphComp
 
 Input:
    file            fstream& from which to load the GrphComp
 
 Output:
    returns         bool value of whether the GrphComp loaded correctly
 ******************************************************************************/
bool GrphComp::load(fstream& file)
{
    if(!file) return false;
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the GrphComp
 ******************************************************************************/
int GrphComp::update()
{
    return 0;
}


