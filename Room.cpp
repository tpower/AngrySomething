/*******************************************************************************
 Filename:                  Room.cpp
 Classname:                 Room

 Description:               This file defines the Room class.
 ******************************************************************************/

#include "Room.h"
#include "Object.h"
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "MultiObject.h"
#include "Sling.h"
#include "Wall.h"
#include "Pig.h"

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

void Room::remove(int i)
{
    delete object[i];
    object.erase(object.begin()+i);
}

void Room::erase()
{
    while(!object.empty())
    {
        delete object[0];
        object.erase(object.begin());
    }
}

/*******************************************************************************
 Name:              load
 Description:       This method dynamically allocates and loads objects in the
                    room

 Output:
    returns         bool value of whether the component loaded correctly
 ******************************************************************************/
bool Room::load(const char* f)
{
    ifstream inFile(f);
    bool loaded;

    if(!inFile)
    {
        loaded = false;
    }

    else
    {
        if(!object.empty())
        {
            erase();
        }

        int type;
        int numObjects;
        inFile >> numObjects;
        for(int i = 0; i < numObjects; i++)
        {
            inFile >> type;
            switch(type)
            {
                case 1:
                {
                    string file, birds;
                    int x, y;
                    inFile >> file >> x >> y >> birds;
                    object.push_back(new Sling(file.c_str(), x, y, birds.c_str()));
                    break;
                }
                case 2:
                {
                    string file;
                    int x, y, xvel, yvel;
                    inFile >> file >> x >> y >> xvel >> yvel;
                    object.push_back(new Pig(file.c_str(),  x, y, xvel, yvel));
                    break;
                }
                case 3:
                {
                    string file;
                    int x, y, xvel, yvel, w, h;
                    inFile >> file >> x >> y >> xvel >> yvel >> w >> h;
                    object.push_back(new Wall(file.c_str(), x, y, xvel, yvel, w, h));
                    break;
                }
            }
        }

        loaded = true;
    }
    return loaded;
}

void Room::add(Object* obj)
{
    object.push_back(obj);
}
