/*******************************************************************************
 Filename:                  Room.cpp
 Classname:                 Room

 Description:               This file defines the Room class. The Room class
                            acts as the model for the Game. It holds state for
                            the game, holds the objects currently in the game,
                            and handles saving and loading the game.
 ******************************************************************************/
#include "Room.h"
#include "Object.h"

Room::Room() : Base(ROOM)
{
    numObjects = 1;
}

DrawableObject* Room::getObjectAt(int i)
{
    return object[i];
}

int Room::getNumObjects()
{
    return numObjects;
}

bool Room::load()
{
    numObjects = 3;

    object.push_back(new DrawableObject("TestA.bmp", 0, 0));
    object.push_back(new DrawableObject("TestB.bmp", 100, 100));
    object.push_back(new DrawableObject("TestC.bmp", 200, 200));

    return true;
}

