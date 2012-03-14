/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object

 Description:               This file defines the Object class. The Object
                            class holds the components that define the objects
                            in the game.

 Last Modified:            				02.28.12
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
Object::Object() : Base(OBJECT)
{
    numComps = 0;
    comp = new Component*[numComps];
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other) : Base(OBJECT)
{

}

/*******************************************************************************
 Name:              ~Object
 Description:       Destructor for Object class
 ******************************************************************************/
Object::~Object()
{
    delete [] comp;
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

    }

    return *this;
}

/*******************************************************************************
 ACCESSORS
 Name:              getComp, getNumObjects
 ******************************************************************************/
Component* Object::getComp(int type)
{
    for(int i = 0; i < numComps; i++)
    {
        if(comp[i]->getType() == type)
        {
            return comp[i];
        }
    }

    return NULL;
}

int Object::getNumComps()
{
    return numComps;
}

/*******************************************************************************
 MUTATORS
 Name:              removeObjectAt
 ******************************************************************************/
void Object::removeCompAt(int index)
{
    Component **temp = new Component*[numComps - 1];

     for(int i = 0; i < index; i++)
     {
         temp[i] = comp[i];
     }

     for(int i = index; i < numComps - 1; i++)
     {
         temp[i] = comp[i+1];
     }

     numComps = numComps - 1;
     comp = temp;
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

    //read number of components in object
    file.read(reinterpret_cast<char*>(&numComps), sizeof(numComps));

    //read component types
    int compTypes[numComps];
    file.read(reinterpret_cast<char*>(&compTypes), sizeof(compTypes));
    
    //create and load components
    for(int i = 0; i < numComps; i++)
    {
        switch(compTypes[i])
        {
            case MECHCOMP:
                comp[i] = new MechComp();
                if(!(comp[i])->load(file)) return false;
                break;

            case TRANCOMP:
                comp[i] = new TranComp();
                if(!(comp[i])->load(file)) return false;
                break;

            case PHYSCOMP:
                comp[i] = new PhysComp();
                if(!(comp[i])->load(file)) return false;
                break;

            case GRPHCOMP:
                comp[i] = new GrphComp();
                if(!(comp[i])->load(file)) return false;
                break;

            default:
                break;
        }
    }

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

    //write number of components in object
    file.write(reinterpret_cast<char*>(&numComps), sizeof(numComps));

    //write component types
    for(int i = 0; i < numComps; i++)
    {
        int tempType = comp[i]->getType();
        file.write(reinterpret_cast<char*>(&tempType), sizeof(tempType));
    }

    //save components
    for(int i = 0; i < numComps; i++)
    {
        if(!(comp[i])->save(file)) return false;
    }

    return true;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the object
 ******************************************************************************/
GameState Object::update()
{
    GameState compState = state;

    for(int i = 0; i < numComps && compState.roomNum == state.roomNum; i++)
    {
        GameState compState = comp[i]->update();

        if(compState.eleState == -1)
        {
            removeCompAt(i);
        }
    }

    state.roomNum = compState.roomNum;

    return state;
}


