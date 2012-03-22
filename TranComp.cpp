/*******************************************************************************
 Filename:                  TranComp.cpp
 Classname:                 TranComp

 Description:               This file defines the TranComp class.

 Last Modified:            				03.09.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "TranComp.h"
#include "Object.h"
#include "PhysComp.h"

/*******************************************************************************
 Name:              TranComp
 Description:       Default constructor for TranComp class
 ******************************************************************************/
TranComp::TranComp() : Component(TRANCOMP)
{
    pos.x = 0;
    pos.y = 0;
    pos.w = 0;
    pos.h = 0;

//    static int count = 0;
//    
//    switch (count)
//    {
//        case 0:             //1st object
//            pos.x = 100;
//            pos.y = 100;
//            pos.w = 80;
//            pos.h = 80;
//            break;
//            
//        case 1:             //2nd object
//            pos.x = 300;
//            pos.y = 300;
//            pos.w = 60;
//            pos.h = 60;
//            break;
//            
//        case 2:             //top wall
//            pos.x = 0;
//            pos.y = 0;
//            pos.w = 640;
//            pos.h = 50;
//            break;
//            
//        case 3:             //left wall
//            pos.x = 0;
//            pos.y = 50;
//            pos.w = 50;
//            pos.h = 380;
//            break;
//            
//        case 4:             //bottom wall
//            pos.x = 0;
//            pos.y = 430;
//            pos.w = 640;
//            pos.h = 50;
//            break;
//            
//        case 5:             //right wall
//            pos.x = 590;
//            pos.y = 50;
//            pos.w = 50;
//            pos.h = 380;
//            break;
//            
//        default:
//            break;
//    }
//    
//    count++;
}

/*******************************************************************************
 Name:              TranComp
 Description:       Copy constructor for TranComp class
 ******************************************************************************/
TranComp::TranComp(const TranComp& other): Component(TRANCOMP)
{
    pos = other.pos;
}

/*******************************************************************************
 Name:              ~TranComp
 Description:       Destructor for TranComp class
 ******************************************************************************/
TranComp::~TranComp()
{

}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for TranComp class

 Input:
 other           const TranComp&
 ******************************************************************************/
TranComp TranComp::operator=(const TranComp& other)
{
    if(&other != this)
    {
        pos = other.pos;
    }

    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getPos
 ******************************************************************************/
SDL_Rect TranComp::getPos()
{
    return pos;
}

/*******************************************************************************
 Name:              load
 Description:       This method loads the TranComp

 Input:
    file            fstream& from which to load the TranComp

 Output:
    returns         bool value of whether the TranComp loaded correctly
 ******************************************************************************/
bool TranComp::load(fstream& file)
{
    if(!file) return false;

    //load pos
    file.read(reinterpret_cast<char*>(&pos.x), sizeof(pos.x));
    file.read(reinterpret_cast<char*>(&pos.y), sizeof(pos.y));
    file.read(reinterpret_cast<char*>(&pos.w), sizeof(pos.w));
    file.read(reinterpret_cast<char*>(&pos.h), sizeof(pos.h));

    return true;
}

/*******************************************************************************
 Name:              save
 Description:       This method saves the current state of the component

 Output:
    returns         bool representing the success of the save
 ******************************************************************************/
bool TranComp::save(fstream& file)
{
    if(!file) return false;

    //write pos
    file.write(reinterpret_cast<char*>(&pos.x), sizeof(pos.x));
    file.write(reinterpret_cast<char*>(&pos.y), sizeof(pos.y));
    file.write(reinterpret_cast<char*>(&pos.w), sizeof(pos.w));
    file.write(reinterpret_cast<char*>(&pos.h), sizeof(pos.h));

    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the TranComp
 ******************************************************************************/
GameState TranComp::update()
{
    PhysComp* p = (PhysComp*)((Object*)getOwner())->getComp(PHYSCOMP);
    
    if(p)
    {
        pos.x += p->getVel().x;
        pos.y += p->getVel().y;
    }
    
    return getState();
}


