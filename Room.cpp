/*******************************************************************************
 Filename:                  Room.cpp
 Classname:                 Room

 Description:               This file defines the Room class.
 ******************************************************************************/
#include "Room.h"
<<<<<<< HEAD
=======
#include "Object.h"
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MultiObject.h"
>>>>>>> upstream/TylerBranch

/*******************************************************************************
 Name:              Room
 Description:       Default constructor for Room class
 ******************************************************************************/
Room::Room()
{

}

/*******************************************************************************
 Name:              Room
 Description:       Copy constructor for Room class

 Input:
    other           Room object to be copied
 ******************************************************************************/
Room::Room(const Room& other)
{

}

/*******************************************************************************
 Name:              ~Room
 Description:       Destructor for Room class
 ******************************************************************************/
Room::~Room()
{

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

    }

    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getObjectAt, getNumObjects
 ******************************************************************************/
Object* Room::getObjectAt(int i)
{
    return object[i];
}

int Room::getNumObjects()
{
    return (int)object.size();
}

/*******************************************************************************
 Name:              load
 Description:       This method dynamically allocates and loads objects in the
                    room

 Output:
    returns         bool value of whether the component loaded correctly
 ******************************************************************************/
bool Room::load()
{
<<<<<<< HEAD
    object.push_back(new Object("TestA.bmp", 0, 0));
    object.push_back(new Object("TestB.bmp", 80, 100));
    object.push_back(new Object("TestC.bmp", 200, 150));
=======
    object.push_back(new MultiObject("TestA.bmp", 0, 0));
    object.push_back(new MultiObject("TestB.bmp", 80, 200));
    object.push_back(new MultiObject("TestC.bmp", 280, 150));
>>>>>>> upstream/TylerBranch

    return true;
}

