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
#include "ClickableObject.h"
#include "PauseButton.h"

/*******************************************************************************
 Name:              Room
 Description:       Default constructor for Room class
 ******************************************************************************/
Room::Room()
{
    roomType = Level;
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

        int dataType;
        int numObjects;
        inFile >> roomType;
        inFile >> numObjects;
        for(int i = 0; i < numObjects; i++)
        {
            inFile >> dataType;
            switch(dataType)
            {
                case 1://Sling
                {
                    string file, birds;
                    int x, y;
                    inFile >> file >> x >> y >> birds;
                    object.push_back(new Sling(file.c_str(), x, y, birds.c_str()));
                    break;
                }
                case 2://Pig
                {
                    string file;
                    int x, y, xvel, yvel;
                    inFile >> file >> x >> y >> xvel >> yvel;
                    object.push_back(new Pig(file.c_str(),  x, y, xvel, yvel));
                    break;
                }
                case 3://Wall
                {
                    string file;
                    int x, y, xvel, yvel, w, h;
                    inFile >> file >> x >> y >> xvel >> yvel >> w >> h;
                    object.push_back(new Wall(file.c_str(), x, y, xvel, yvel, w, h));
                    break;
                }
                case 4://ClickableObject
                {
                    string file;
                    int x, y, w, h, v;
                    inFile >> file >> x >> y >> w >> h >> v;
                    object.push_back(new ClickableObject(file.c_str(), x, y, w, h, v));
                    break;
                }
                case 5://PauseButton
                {
                    string file;
                    int x, y, w, h;
                    inFile >> file >> x >> y >> w >> h;
                    object.push_back(new PauseButton(file.c_str(), x, y, w, h));
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
