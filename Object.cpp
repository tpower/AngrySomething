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
    comp = new Component[1];
    numComps = 1;
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other) : Base("object")
{
    numComps = other.numComps;
    
    comp = new Component[numComps];
    
    for(int i = 0; i < numComps; i++)
    {
        comp[i] = other.comp[i];
    }
}

/*******************************************************************************
 Name:              ~Object
 Description:       Destructor for Object class
 ******************************************************************************/
Object::~Object()
{
    if(comp) delete [] comp;
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
        numComps = other.numComps;
        
        if(comp) delete [] comp;
        comp = new Component[numComps];
        
        for(int i = 0; i < numComps; i++)
        {
            comp[i] = other.comp[i];
        }
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
 ******************************************************************************/
void Object::load()
{
    
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the object
 ******************************************************************************/
int Object::update()
{
    for(int i = 0; i < numComps; i++)
    {
        int temp = comp[i].update();
        
        if(temp)
        {
            //implementation reacting to state of object
        }
    }
    
    return 0;
}


