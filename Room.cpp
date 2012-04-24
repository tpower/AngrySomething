/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room
 
 Description:               The Room class is a container for objects in the
                            game and handles loading levels from files.
 ******************************************************************************/

#include <iostream>

#include "Room.h"
#include "Object.h"
#include "DrawableObject.h"
#include "PhysicalObject.h"
#include "Sling.h"
#include "Wall.h"
#include "Enemy.h"
#include "ClickableObject.h"
#include "PauseButton.h"
#include "MenuItem.h"
#include "NonInteractionObject.h"
#include "DestructableWall.h"
#include "Spaceship.h"
#include "ConversationBox.h"
#include "Timer.h"

/*******************************************************************************
 Name:              Room
 Description:       Default constructor
 ******************************************************************************/
Room::Room()
{
    roomType = Level;
    background = NULL;
}

/*******************************************************************************
 Name:              ~Room
 Description:       Destructor
 ******************************************************************************/
Room::~Room()
{
    SDL_FreeSurface(background);
}

/*******************************************************************************
 ACCESSORS
 Name:              getObjectAt, getNumObjects, getBackground
 ******************************************************************************/
Object* Room::getObjectAt(int i)
{
    return object[i];
}

int Room::getNumObjects()
{
    return (int)object.size();
}

SDL_Surface* Room::getBackground()
{
    return background;
}

/*******************************************************************************
 MODIFIERS
 Name:              remove, setBackground, erase, add
 ******************************************************************************/
void Room::remove(int i)
{
    delete object[i];
    object.erase(object.begin()+i);
}

void Room::setBackground(const char* file)
{
    SDL_FreeSurface(background);
    background = SDL_LoadBMP(file);
    if(!background)
    {
        cout << "background file error" << endl;
    }
}

void Room::erase()
{
    while(!object.empty())
    {
        delete object[0];
        object.erase(object.begin());
    }
}

void Room::add(Object* obj)
{
    object.push_back(obj);
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
                    string file, file2, birds;
                    int x, y;
                    inFile >> file >> file2 >> x >> y >> birds;
                    object.push_back(new Sling(file.c_str(), file2.c_str(), x, y, birds.c_str()));
                    break;
                }
                case 2://Pig
                {
                    string file;
                    int x, y, xvel, yvel;
                    inFile >> file >> x >> y >> xvel >> yvel;
                    object.push_back(new Enemy(file.c_str(),  x, y, xvel, yvel));
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
                case 8://Spaceship
                {
                    string file;
                    int x, y, d, t;
                    inFile >> file >> x >> y >> d >> t;
                    object.push_back(new Spaceship(file.c_str(), x, y, d, t));
                    break;
                }
                case 9://ConversationBox
                {
                    int x, y;
                    string data;
                    inFile >> x >> y >> data;
                    object.push_back(new ConversationBox(x, y, data.c_str()));
                    break;
                }
                case 10://Timer
                {
                    int t;
                    inFile >> t;
                    object.push_back(new Timer(t));
                    break;
                }
            }
        }

        setBackground(backgroundFile.c_str());
        
        MechanicsObject::resetScore();

        loaded = true;
    }
    
    return loaded;
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the Room
 
 Output:
    returns         bool TRUE
 ******************************************************************************/
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

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the Room if it is paused
 
 Output:
    returns         bool TRUE
 ******************************************************************************/
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
