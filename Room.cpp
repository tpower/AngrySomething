/*******************************************************************************
 Filename:                  Room.cpp
 Classname:                 Room

 Description:               This file defines the Room class.
 ******************************************************************************/

#include "Room.h"
#include "Object.h"
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "Sling.h"
#include "Wall.h"
#include "Pig.h"
#include "ClickableObject.h"
#include "PauseButton.h"
#include "MenuItem.h"
#include "NonInteractionObject.h"
#include "DestructableWall.h"
#include "Ground.h"

/*******************************************************************************
 ACCESSORS
 Name:              getObjectAt, getNumObjects
 ******************************************************************************/
Room::Room()
{
    roomType = Level;
}

Room::~Room()
{
    SDL_FreeSurface(background);
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

void Room::setBackground(char* file)
{
    SDL_FreeSurface(background);
    background = SDL_LoadBMP(file);
}

void Room::erase()
{
    while(!object.empty())
    {
        delete object[0];
        object.erase(object.begin());
    }
}

SDL_Surface* Room::getBackground()
{
    return background;
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
        string backgroundFile;

        inFile >> backgroundFile;
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
                case 5://MenuItem
                {
                    string file;
                    int x, y, w, h, v;
                    inFile >> file >> x >> y >> w >> h >> v;
                    object.push_back(new MenuItem(file.c_str(), x, y, w, h, v));
                    break;
                }
                case 6://NonInteractionObject
                {
                    string file;
                    int x, y;
                    inFile >> file >> x >> y;
                    object.push_back(new NonInteractionObject(file.c_str(), x, y));
                    break;
                }
                case 7://DestructableWall
                {
                    string file;
                    int x, y, xvel, yvel, w, h;
                    inFile >> file >> x >> y >> xvel >> yvel >> w >> h;
                    object.push_back(new DestructableWall(file.c_str(), x, y, xvel, yvel, w, h));
                    break;
                }
                case 8: //Ground
                {
                    string file;
                    int x, y, xvel, yvel, w, h;
                    inFile >> file >> x >> y >> xvel >> yvel >> w >> h;
                    object.push_back(new Ground(file.c_str(), x, y, xvel, yvel, w, h));
                    break;
                }
            }
        }

        background = SDL_LoadBMP(backgroundFile.c_str());

        loaded = true;
    }
    return loaded;
}

void Room::add(Object* obj)
{
    object.push_back(obj);
}

//Not really sure that we actually want this as a bool
bool Room::pause()
{
    Object* obj;

    for(int i = 0; i < getNumObjects(); i++)
    {
        obj = getObjectAt(i);
        (obj)->pause();
    }
    return true;
}

//Not really sure that we actually want this as a bool
bool Room::unpause()
{
    Object* obj;

    for(int i = 0; i < getNumObjects(); i++)
    {
        obj = getObjectAt(i);
        (obj)->unpause();
    }
    return true;
}
