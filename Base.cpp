/*******************************************************************************
 Filename:                  Base.cpp
 Classname:                 Base
 
 Description:               This file defines the Base class. The Base class
                            serves as the template for all classes. It will
                            handle the fundamental actions of classes, such
                            as Value Observing.
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "Base.h"

int Base::counter = 0;


/*******************************************************************************
 Name:              Base
 Description:       Default constructor for Base class
 ******************************************************************************/
Base::Base()
{
    id = counter++;
    type = "base";
}

/*******************************************************************************
 Name:              Base
 Description:       Secondary constructor for Base class
 
 Input:
    t               string representing the type of object
 ******************************************************************************/
Base::Base(string t)
{
    id = counter++;
    type = t;
}

/*******************************************************************************
 Name:              Base
 Description:       Copy constructor for Base class
 ******************************************************************************/
Base::Base(const Base& other)
{
    type = other.type;
    id = counter++;
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
        type = other.type;
    }
    
    return *this;
}

/*******************************************************************************
 ACCESSSORS
 Name:              getID, getType
 ******************************************************************************/
int Base::getID()
{
    return id;
}

string Base::getType()
{
    return type;
}


