/*******************************************************************************
 Filename:                  TempComp.cpp
 Classname:                 TempComp
 
 Description:               This file declares the TempComp class. It is just
 used for testing purposes to instantiate a subclass
 of the abstract class, Component.
 
 Last Modified:            				03.02.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "TempComp.h"
#include <iostream>

using namespace std;

/*******************************************************************************
 Name:              TempComp
 Description:       Default constructor for TempComp class
 ******************************************************************************/
TempComp::TempComp() : Component()
{
    numData = 4;
    charData = new char[numData];
    charData = "ABC";
}

/*******************************************************************************
 Name:              TempComp
 Description:       Copy constructor for TempComp class
 ******************************************************************************/
TempComp::TempComp(const TempComp& other)
{
    numData = other.numData;
    charData = new char[strlen(other.charData)];
    strcpy(charData, other.charData);
}

/*******************************************************************************
 Name:              ~TempComp
 Description:       Destructor for TempComp class
 ******************************************************************************/
TempComp::~TempComp()
{
    delete [] charData;
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the TempComp
 
 Output:
    returns         bool value of whether the TempComp loaded correctly
 ******************************************************************************/
bool TempComp::load(fstream& file)
{
    if(!file) return false;
    
    file.read(reinterpret_cast<char*>(numData), sizeof(numData));
    file.read(reinterpret_cast<char*>(charData), numData * sizeof(charData));
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the TempComp
 ******************************************************************************/
int TempComp::update()
{
    return 0;
}


