/*******************************************************************************
 Filename:                  GrphComp.cpp
 Classname:                 GrphComp
 
 Description:               This file defines the GrphComp class.
 
 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "GrphComp.h"
#include <iostream>
using namespace std;

/*******************************************************************************
 Name:              GrphComp
 Description:       Default constructor for GrphComp class
 ******************************************************************************/
GrphComp::GrphComp() : Component(GRPHCOMP)
{
    image   = new SDL_Surface;
    frame.x = 0;
    frame.y = 0;
    frame.w = 0;
    frame.h = 0;
}

/*******************************************************************************
 Name:              GrphComp
 Description:       Copy constructor for GrphComp class
 ******************************************************************************/
GrphComp::GrphComp(const GrphComp& other) : Component(GRPHCOMP)
{
    *image  = *(other.image);   //may not have proper assignment capabilities?
    frame   = other.frame;
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
        *image  = *(other.image);   //may not have proper assignment capabilities?
        frame   = other.frame;
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
    file.read(reinterpret_cast<char*>(pathLen), sizeof(pathLen));
    
    filePath = new char[pathLen];
    file.read(reinterpret_cast<char*>(filePath), sizeof(filePath) * pathLen);
    
    //load image
    image = SDL_LoadBMP(filePath);
    if(!image)
    {
        cout << "ERROR: could not load " << filePath << endl;
        return false;
    }
    
    //load frame
    file.read(reinterpret_cast<char*>(frame.x), sizeof(frame.x));
    file.read(reinterpret_cast<char*>(frame.y), sizeof(frame.y));
    file.read(reinterpret_cast<char*>(frame.w), sizeof(frame.w));
    file.read(reinterpret_cast<char*>(frame.h), sizeof(frame.h));
    
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
    file.write(reinterpret_cast<char*>(pathLen), sizeof(pathLen));
    file.write(reinterpret_cast<char*>(filePath), sizeof(filePath) * pathLen);
    
    //write frame
    file.write(reinterpret_cast<char*>(frame.x), sizeof(frame.x));
    file.write(reinterpret_cast<char*>(frame.y), sizeof(frame.y));
    file.write(reinterpret_cast<char*>(frame.w), sizeof(frame.w));
    file.write(reinterpret_cast<char*>(frame.h), sizeof(frame.h));
    
    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the GrphComp
 ******************************************************************************/
int GrphComp::update()
{
    return 0;
}


