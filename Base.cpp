/*******************************************************************************
 Filename:                  Base.cpp
 Classname:                 Base

 Description:               This file defines the Base class. The Base class
                            serves as the template for all classes.
 ******************************************************************************/

#include "Base.h"

int Base::idGen = 0;

/*******************************************************************************
 Name:              Base
 Description:       Default constructor for Base class
 ******************************************************************************/
Base::Base()
{
    id              = idGen++;
    type            = BASE;
    state.roomNum   = 0;
    state.eleState  = 0;
}

/*******************************************************************************
 Name:              Base
 Description:       Secondary constructor for Base class

 Input:
    t               int representing the type of object
 ******************************************************************************/
Base::Base(int t)
{
    id              = idGen++;
    type            = t;
    state.roomNum   = 0;
    state.eleState  = 0;
}

/*******************************************************************************
 Name:              Base
 Description:       Copy constructor for Base class
 ******************************************************************************/
Base::Base(const Base& other)
{
    type    = other.type;
    id      = idGen++;
    state   = other.state;
}

/*******************************************************************************
 Name:              ~Base
 Description:       Destructor for Base class
 ******************************************************************************/
Base::~Base()
{
    
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for Base class

 Input:
    other           const Base&
 ******************************************************************************/
Base Base::operator=(const Base& other)
{
    if(&other != this)
    {
        type    = other.type;
        id      = idGen++;
        state   = other.state;
    }

    return *this;
}

/*******************************************************************************
 MODIFIERS
 Name:              setState
 ******************************************************************************/
void Base::setState(GameState s)
{
    state = s;
}

/*******************************************************************************
 ACCESSSORS
 Name:              getID, getType, getState
 ******************************************************************************/
int Base::getID() const
{
    return id;
}

int Base::getType() const
{
    return type;
}

GameState Base::getState() const
{
    return state;
}

