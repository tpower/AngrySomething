/*******************************************************************************
 Filename:                  Room.cpp
 Classname:                 Room
 
 Description:               This file defines the Room class. The Room class
                            acts as the model for the Game. It holds state for
                            the game, holds the objects currently in the game,
                            and handles saving and loading the game.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "Room.h"

/*******************************************************************************
 Name:              Room
 Description:       Default constructor for Room class
 ******************************************************************************/
Room::Room() : Base("room")
{
    object = new Object[1];
    numObjects = 1;
}

/*******************************************************************************
 Name:              Room
 Description:       Copy constructor for Room class
 
 Input:
    other           Room object to be copied
 ******************************************************************************/
Room::Room(const Room& other) : Base("room")
{
    numObjects = other.numObjects;
    
    object = new Object[numObjects];
    
    for(int i = 0; i < numObjects; i++)
    {
        object[i] = other.object[i];
    }
}

/*******************************************************************************
 Name:              ~Room
 Description:       Destructor for Room class
 ******************************************************************************/
Room::~Room()
{
    if(object) delete [] object;
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Room class
 
 Input:
    other           const Room&
 ******************************************************************************/
Room Room::operator=(const Room& other)
{
    if(&other != this)
    {
        numObjects = other.numObjects;
        
        if(object) delete [] object;
        object = new Object[numObjects];
        
        for(int i = 0; i < numObjects; i++)
        {
            object[i] = other.object[i];
        }
    }
    
    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getObjectAt, getNumObjects
 ******************************************************************************/
Object& Room::getObjectAt(int i)
{
    return object[i];
}

int Room::getNumObjects()
{
    return numObjects;
}

/*******************************************************************************
 Name:              update
 Description:       This method enumerates through the objects in the room and
                    calls their update methods
 ******************************************************************************/
void Room::update()
{
    
}
