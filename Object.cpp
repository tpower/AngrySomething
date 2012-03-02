/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object
 
 Description:               This file defines the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "Object.h"
#include <iostream>

using namespace std;

/*******************************************************************************
 Name:              Object
 Description:       Default constructor for Object class
 ******************************************************************************/
Object::Object() : Base("object")
{
    numComps = 0;
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other) : Base("object")
{
    
}

/*******************************************************************************
 Name:              ~Object
 Description:       Destructor for Object class
 ******************************************************************************/
Object::~Object()
{
    delete [] comp;
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Object class
 
 Input:
    other           const Object&
 ******************************************************************************/
Object Object::operator=(const Object& other)
{
    if(&other != this)
    {
        
    }
    
    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getObjectAt, getNumObjects
 ******************************************************************************/
Component& Object::getCompAt(int i)
{
    return comp[i];
}

int Object::getNumComps()
{
    return numComps;
}

/*******************************************************************************
 Name:              load
 Description:       This method dynamically allocates and loads components in
                    the room
 
 Output:
    returns         bool value of whether the component loaded correctly
 ******************************************************************************/
bool Object::load()
{
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the object
 ******************************************************************************/
int Object::update()
{
    int compsUpdated = 0;
    
    for(int i = 0; i < numComps; i++)
    {
        int temp = comp[i].update();
        
        if(temp)
        {
            compsUpdated++;
        }
    }
    
    return compsUpdated;
}


