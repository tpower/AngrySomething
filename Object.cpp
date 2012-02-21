/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object
 
 Description:               This file defines the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 
 Last Modified:            				02.04.12
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
    //Set default location
    loc.x = 0;
    loc.y = 0;
    
    //Set default velocity vector
    loc.w = 1;
    loc.h = 1;
    
    //Set default frame
    frame.x = 0;
    frame.y = 0;
    frame.w = 200;
    frame.h = 200;
    
    //Load default image
    image = SDL_LoadBMP("object.bmp");
    if(!image)
    {
        cout << "ERROR: Object:Object:SDL_LoadBMP" << endl;
        exit(-1);
    }
    
    needsUpdate = true;
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other) : Base("object")
{
    loc         = other.loc;
    frame       = other.frame;
    *image      = *(other.image);
    needsUpdate = other.needsUpdate;
}

/*******************************************************************************
 Name:              ~Object
 Description:       Destructor for Object class
 ******************************************************************************/
Object::~Object()
{
    SDL_FreeSurface(image);
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
        loc         = other.loc;
        frame       = other.frame;
        *image      = *(other.image);
        needsUpdate = other.needsUpdate;
    }
    
    return *this;
}

/*******************************************************************************
 MODIFIERS
 Name:              setLoc, setFrame, setImage, setNeedsUpdate
 ******************************************************************************/
void Object::setLoc(const SDL_Rect& l)
{
    loc = l;
}

void Object::setFrame(const SDL_Rect& f)
{
    frame = f;
}

void Object::setImage(const SDL_Surface& i)
{
    *image = i;
}

void Object::setNeedsUpdate(bool b)
{
    needsUpdate = b;
}

/*******************************************************************************
 ACCESSORS
 Name:              getLoc, getFrame, getImage, getNeedsUpdate
 ******************************************************************************/
SDL_Rect Object::getLoc() const
{
    return loc;
}

SDL_Rect Object::getFrame() const
{
    return frame;
}

SDL_Surface Object::getImage() const
{
    return *image;
}

bool Object::getNeedsUpdate()
{
    return needsUpdate;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the object
 ******************************************************************************/
void Object::update()
{
    if(loc.x < 0  || loc.x + frame.w > 640)
    {
        loc.w *= -1;
    }
    
    if(loc.y < 0  || loc.y + frame.h > 480)
    {
        loc.h *= -1;
    }
    
    loc.x += loc.w;
    loc.y += loc.h;
    
    frame.x += loc.w;
    frame.y += loc.h;
    
    needsUpdate = true;
}

/*******************************************************************************
 Name:              load
 Description:       loads an object from a file
 ******************************************************************************/
void Object::load()
{
    
}

/*******************************************************************************
 Name:              save
 Description:       saves an object to a file
 ******************************************************************************/
void Object::save()
{
    
}


