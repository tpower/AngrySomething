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
    
//    static int count = 0;
//    
//    switch (count)
//    {
//        case 0:
//            vel.x = 1;
//            vel.y = 1;
//            acc.x = 0;
//            acc.y = 0;
//            break;
//            
//        case 1:
//            vel.x = 1;
//            vel.y = -1;
//            acc.x = 0;
//            acc.y = 0;
//            break;
//            
//        case 2:
//            vel.x = 0;
//            vel.y = 0;
//            acc.x = 0;
//            acc.y = 0;
//            break;
//            
//        case 3:
//            vel.x = 0;
//            vel.y = 0;
//            acc.x = 0;
//            acc.y = 0;
//            break;
//            
//        case 4:
//            vel.x = 0;
//            vel.y = 0;
//            acc.x = 0;
//            acc.y = 0;
//            break;
//            
//        case 5:
//            vel.x = 0;
//            vel.y = 0;
//            acc.x = 0;
//            acc.y = 0;
//            break;
//            
//        default:
//            break;
//    }
//    
//    count++;
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
 ACCESSORS
 Name:              getVel, getAcc
 ******************************************************************************/
vect PhysComp::getVel()
{
    return vel;
}

vect PhysComp::getAcc()
{
    return acc;
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
    file.read(reinterpret_cast<char*>(&vel.x), sizeof(vel.x));
    file.read(reinterpret_cast<char*>(&vel.y), sizeof(vel.y));

    //load acc
    file.read(reinterpret_cast<char*>(&acc.x), sizeof(acc.x));
    file.read(reinterpret_cast<char*>(&acc.y), sizeof(acc.y));

    return true;
}

/*******************************************************************************
 Name:              save
 Description:       This method saves the current state of the component

 Output:
    returns         bool representing the success of the save
 ******************************************************************************/
bool PhysComp::save(fstream& file)
{
    if(!file) return false;

    //write vel
    file.write(reinterpret_cast<char*>(&vel.x), sizeof(vel.x));
    file.write(reinterpret_cast<char*>(&vel.y), sizeof(vel.y));

    //write acc
    file.write(reinterpret_cast<char*>(&acc.x), sizeof(acc.x));
    file.write(reinterpret_cast<char*>(&acc.y), sizeof(acc.y));

    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the PhysComp
 ******************************************************************************/
GameState PhysComp::update()
{    
    return getState();
}


