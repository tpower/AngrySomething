/*******************************************************************************
 Filename:                  GrphComp.cpp
 Classname:                 GrphComp

 Description:               This file defines the GrphComp class.

 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include <iostream>

#include "GrphComp.h"
#include "Game.h"
#include "View.h"
#include "Object.h"

using namespace std;

/*******************************************************************************
 Name:              GrphComp
 Description:       Default constructor for GrphComp class
 ******************************************************************************/
GrphComp::GrphComp() : Component(GRPHCOMP)
{
    image   = NULL;
    frame.x = 0;
    frame.y = 0;
    frame.w = 0;
    frame.h = 0;
    filePath = new char[10];
    
//    static int count = 0;
//    
//    switch (count)
//    {
//        case 0:
//            frame.x = 100;
//            frame.y = 100;
//            frame.w = 80;
//            frame.h = 80;
//            filePath = "Object.bmp";
//            break;
//            
//        case 1:
//            frame.x = 300;
//            frame.y = 300;
//            frame.w = 60;
//            frame.h = 60;
//            filePath = "Object2.bmp";
//            break;
//            
//        case 2:
//            frame.x = 0;
//            frame.y = 0;
//            frame.w = 640;
//            frame.h = 50;
//            filePath = "Object3.bmp";
//            break;
//            
//        case 3:
//            frame.x = 0;
//            frame.y = 50;
//            frame.w = 50;
//            frame.h = 380;
//            filePath = "Object3.bmp";
//            break;
//            
//        case 4:
//            frame.x = 0;
//            frame.y = 430;
//            frame.w = 640;
//            frame.h = 50;
//            filePath = "Object3.bmp";
//            break;
//            
//        case 5:
//            frame.x = 590;
//            frame.y = 50;
//            frame.w = 50;
//            frame.h = 380;
//            filePath = "Object3.bmp";
//            break;
//            
//        default:
//            break;
//    }
//    
//    count++;
}

/*******************************************************************************
 Name:              GrphComp
 Description:       Copy constructor for GrphComp class
 ******************************************************************************/
GrphComp::GrphComp(const GrphComp& other) : Component(GRPHCOMP)
{
    *image      = *(other.image);
    frame       = other.frame;
    *filePath   = *(other.filePath);
}

/*******************************************************************************
 Name:              ~GrphComp
 Description:       Destructor for GrphComp class
 ******************************************************************************/
GrphComp::~GrphComp()
{
    SDL_FreeSurface(image);
    delete [] filePath;
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for GrphComp class

 Input:
    other           const GrphComp&
 ******************************************************************************/
GrphComp GrphComp::operator=(const GrphComp& other)
{
    if(&other != this)
    {
        *image      = *(other.image);
        frame       = other.frame;
        *filePath   = *(other.filePath);
    }

    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getImage, getFrame
 ******************************************************************************/
SDL_Surface* GrphComp::getImage()
{
    return image;
}
SDL_Rect GrphComp::getFrame()
{
    return frame;
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the GrphComp

 Input:
    file            fstream& from which to load the GrphComp

 Output:
    returns         bool value of whether the GrphComp loaded correctly
 ******************************************************************************/
bool GrphComp::load(fstream& file)
{
    if(!file) return false;

    //load filePath
    int pathLen;
    file.read(reinterpret_cast<char*>(&pathLen), sizeof(pathLen));

    delete [] filePath;
    filePath = new char[pathLen];
    file.read(reinterpret_cast<char*>(filePath), sizeof(filePath) * pathLen);

    //load image
    SDL_FreeSurface(image);
    image = SDL_LoadBMP(filePath);
    if(!image)
    {
        cout << "ERROR: could not load " << filePath << endl;
        return false;
    }

    //load frame
    file.read(reinterpret_cast<char*>(&frame.x), sizeof(frame.x));
    file.read(reinterpret_cast<char*>(&frame.y), sizeof(frame.y));
    file.read(reinterpret_cast<char*>(&frame.w), sizeof(frame.w));
    file.read(reinterpret_cast<char*>(&frame.h), sizeof(frame.h));

    return true;
}

/*******************************************************************************
 Name:              save
 Description:       This method saves the current state of the component

 Output:
    returns         bool representing the success of the save
 ******************************************************************************/
bool GrphComp::save(fstream& file)
{
    if(!file) return false;

    //write filePath
    int pathLen = (int)strlen(filePath) + 1;    //1 accounts for '\0'
    file.write(reinterpret_cast<char*>(&pathLen), sizeof(pathLen));
    file.write(reinterpret_cast<char*>(filePath), sizeof(filePath) * pathLen);

    //write frame
    file.write(reinterpret_cast<char*>(&frame.x), sizeof(frame.x));
    file.write(reinterpret_cast<char*>(&frame.y), sizeof(frame.y));
    file.write(reinterpret_cast<char*>(&frame.w), sizeof(frame.w));
    file.write(reinterpret_cast<char*>(&frame.h), sizeof(frame.h));

    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the GrphComp
 ******************************************************************************/
GameState GrphComp::update()
{
    View* v = (((Game*)(getOwner()->getOwner()->getOwner()))->getView());
    
    v->draw((Object*)getOwner());
    
//    frame.x++;
//    frame.y++;
    
    return getState();
}


