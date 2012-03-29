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

Room::Room()
{
    
}

Object* Room::getObjectAt(int i)
{
    return object[i];
}

int Room::getNumObjects()
{
    return (int)object.size();
}

bool Room::load()
{
    object.push_back(new Object(0, 0));
    object.push_back(new Object(80, 100));
    object.push_back(new Object(200, 150));

    return true;
}

