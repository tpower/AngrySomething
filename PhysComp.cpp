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
    vel.x = 0;
    vel.y = 0;
    acc.x = 0;
    acc.y = 0;
}

/*******************************************************************************
 Name:              PhysComp
 Description:       Copy constructor for PhysComp class
 ******************************************************************************/
PhysComp::PhysComp(const PhysComp& other) : Component(PHYSCOMP)
{
    vel = other.vel;
    acc = other.acc;
}

/*******************************************************************************
 Name:              ~PhysComp
 Description:       Destructor for PhysComp class
 ******************************************************************************/
PhysComp::~PhysComp()
{
    
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for PhysComp class
 
 Input:
 other           const PhysComp&
 ******************************************************************************/
PhysComp PhysComp::operator=(const PhysComp& other)
{
    if(&other != this)
    {
        vel = other.vel;
        acc = other.acc;
    }
    
    return *this;
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
    
    //load vel
    file.read(reinterpret_cast<char*>(vel.x), sizeof(vel.x));
    file.read(reinterpret_cast<char*>(vel.y), sizeof(vel.y));
    
    //load acc
    file.read(reinterpret_cast<char*>(acc.x), sizeof(acc.x));
    file.read(reinterpret_cast<char*>(acc.y), sizeof(acc.y));

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


