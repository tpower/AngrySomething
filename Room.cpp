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
 Name:              load
 Description:       This method dynamically allocates and loads objects in the 
                    room
 
 Input:
    file            fstream& from which to load the Room
 
 Output:
    returns         bool value of whether the component loaded correctly
 ******************************************************************************/
bool Room::load(fstream& file)
{
    if(!file) return false;
    
    //read number of objects in room
    file.read(reinterpret_cast<char*>(numObjects), sizeof(numObjects));
    
    //create objects
    delete [] object;
    object = new Object[numObjects];
    
    //load objects
    for(int i = 0; i < numObjects; i++)
    {
        if(!object[i].load(file)) return false;
    }
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method enumerates through the objects in the room and
                    calls their update methods
 ******************************************************************************/
int Room::update()
{
    int objectsUpdated = 0;
    
    for(int i = 0; i < numObjects; i++)
    {
        int temp = object[i].update();
        
        if(temp < 0)
        {
//            if(object[i].getType() == "roomController")
//                load(object[i].getNextRoom());
//            else removeObjectAt(i);
        }
        else if(temp > 0)
        {
            objectsUpdated++;
        }
    }
    
    return objectsUpdated;
}
