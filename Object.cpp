/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object

 Description:               This file defines the Object class. The Object
                            class holds the components that define the objects
                            in the game.
 ******************************************************************************/

#include "Object.h"

/*******************************************************************************
 Name:              Object
 Description:       Default constructor for Object class
 ******************************************************************************/
Object::Object() : Base(OBJECT)
{
    //init pos
    pos.x = 0;
    pos.y = 0;
    pos.w = 0;
    pos.h = 0;
    
    //init vel
    vel.x = 0;
    vel.y = 0;
    
    //init acc
    acc.x = 0;
    acc.y = 0;
    
    //init frame
    frame.x = 0;
    frame.y = 0;
    frame.w = 320;
    frame.h = 240;
    
    //init filePath
    filePath = "object.bmp";
    
    //load image from file
    image = SDL_LoadBMP(filePath.c_str());
    if(!image)
    {
        exit(-1);
    }
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other) : Base(OBJECT)
{
    pos         = other.pos;
    vel         = other.vel;
    acc         = other.acc;
    frame       = other.frame;
    filePath    = other.filePath;
    *image      = *(other.image);
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
        pos         = other.pos;
        vel         = other.vel;
        acc         = other.acc;
        frame       = other.frame;
        filePath    = other.filePath;
        *image      = *(other.image);
    }
    
    return *this;
}

/*******************************************************************************
 MUTATORS
 Name:              setPos, setVel, setAcc, setFrame, setFilePath
 ******************************************************************************/
void Object::setPos(SDL_Rect p)
{
    pos = p;
}

void Object::setVel(vect v)
{
    vel = v;
}

void Object::setAcc(vect a)
{
    acc = a;
}

void Object::setFrame(SDL_Rect f)
{
    frame = f;
}

void Object::setFilePath(string p)
{
    filePath = p;
}

/*******************************************************************************
 ACCESSORS
 Name:              getPos, getVel, getAcc, getFrame, getFilePath, getImage
 ******************************************************************************/
SDL_Rect Object::getPos()
{
    return pos;
}

vect Object::getVel()
{
    return vel;
}

vect Object::getAcc()
{
    return acc;
}

SDL_Rect Object::getFrame()
{
    return frame;
}

string Object::getFilePath()
{
    return filePath;
}

SDL_Surface* Object::getImage()
{
    return image;
}

/*******************************************************************************
 Name:              load
 Description:       This method dynamically allocates and loads components in
                    the room

 Input:
    file            fstream& from which to load the Object

 Output:
    returns         bool value of whether the component loaded correctly
 ******************************************************************************/
bool Object::load(fstream& file)
{
    if(!file) return false;
    
    //load pos
    file.read(reinterpret_cast<char*>(&pos.x), sizeof(pos.x));
    file.read(reinterpret_cast<char*>(&pos.y), sizeof(pos.y));
    file.read(reinterpret_cast<char*>(&pos.w), sizeof(pos.w));
    file.read(reinterpret_cast<char*>(&pos.h), sizeof(pos.h));
    
    //load vel
    file.read(reinterpret_cast<char*>(&vel.x), sizeof(vel.x));
    file.read(reinterpret_cast<char*>(&vel.y), sizeof(vel.y));
    
    //load acc
    file.read(reinterpret_cast<char*>(&acc.x), sizeof(acc.x));
    file.read(reinterpret_cast<char*>(&acc.y), sizeof(acc.y));
    
    //load frame
    file.read(reinterpret_cast<char*>(&frame.x), sizeof(frame.x));
    file.read(reinterpret_cast<char*>(&frame.y), sizeof(frame.y));
    file.read(reinterpret_cast<char*>(&frame.w), sizeof(frame.w));
    file.read(reinterpret_cast<char*>(&frame.h), sizeof(frame.h));
    
    //load filePath * NOT IMPLEMENTED
    
    //load image * NOT IMPLEMENTED
    
    return true;
}

/*******************************************************************************
 Name:              save
 Description:       This method saves the current state of the object

 Output:
    returns         bool representing the success of the save
 ******************************************************************************/
bool Object::save(fstream& file)
{
    if(!file) return false;
    
    //load pos
    file.write(reinterpret_cast<char*>(&pos.x), sizeof(pos.x));
    file.write(reinterpret_cast<char*>(&pos.y), sizeof(pos.y));
    file.write(reinterpret_cast<char*>(&pos.w), sizeof(pos.w));
    file.write(reinterpret_cast<char*>(&pos.h), sizeof(pos.h));
    
    //load vel
    file.write(reinterpret_cast<char*>(&vel.x), sizeof(vel.x));
    file.write(reinterpret_cast<char*>(&vel.y), sizeof(vel.y));
    
    //load acc
    file.write(reinterpret_cast<char*>(&acc.x), sizeof(acc.x));
    file.write(reinterpret_cast<char*>(&acc.y), sizeof(acc.y));
    
    //load frame
    file.write(reinterpret_cast<char*>(&frame.x), sizeof(frame.x));
    file.write(reinterpret_cast<char*>(&frame.y), sizeof(frame.y));
    file.write(reinterpret_cast<char*>(&frame.w), sizeof(frame.w));
    file.write(reinterpret_cast<char*>(&frame.h), sizeof(frame.h));
    
    //load filePath * NEEDS IMPLEMENTATION
    
    //load image * NEEDS IMPLEMENTATION
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the object
 ******************************************************************************/
GameState Object::update()
{
    return state;
}


