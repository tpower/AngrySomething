/*******************************************************************************
 Filename:                  TranComp.cpp
 Classname:                 TranComp
 
 Description:               This file defines the TranComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "TranComp.h"

/*******************************************************************************
 Name:              TranComp
 Description:       Default constructor for TranComp class
 ******************************************************************************/
TranComp::TranComp() : Component()
{
    
}

/*******************************************************************************
 Name:              TranComp
 Description:       Copy constructor for TranComp class
 ******************************************************************************/
TranComp::TranComp(const TranComp& other)
{
    
}

/*******************************************************************************
 Name:              ~TranComp
 Description:       Destructor for TranComp class
 ******************************************************************************/
TranComp::~TranComp()
{
    
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for TranComp class
 
 Input:
 other           const TranComp&
 ******************************************************************************/
TranComp TranComp::operator=(const TranComp& other)
{
    if(&other != this)
    {
        
    }
    
    return *this;
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the TranComp
 
 Input:
    file            fstream& from which to load the TranComp
 
 Output:
    returns         bool value of whether the TranComp loaded correctly
 ******************************************************************************/
bool TranComp::load(fstream& file)
{
    if(!file) return false;
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the TranComp
 ******************************************************************************/
int TranComp::update()
{
    return 0;
}


