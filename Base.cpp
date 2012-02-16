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

Base::Base()
{
    id = counter++;
    type = "base";
}

Base::Base(string t)
{
    id = counter++;
    type = t;
}

Base::Base(const Base& other)
{
    type = other.type;
    id = counter++;
}

int Base::getID()
{
    return id;
}

string Base::getType()
{
    return type;
}