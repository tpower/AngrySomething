/*******************************************************************************
 Filename:                  View.cpp
 Classname:                 View
 
 Description:               This file defines the View class. The View class is
                            responsible for output to the screen. Most of the
                            SDL implementation will belong in this class.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#include "View.h"
#include <iostream>

/*******************************************************************************
 Name:              View
 Description:       Default constructor for View class
 ******************************************************************************/
View::View() : Base(VIEW)
{
    
}

/*******************************************************************************
 Name:              View
 Description:       Copy constructor for View class
 
 Input:
    other           View to be copied
 ******************************************************************************/
View::View(const View& other) : Base(VIEW)
{
    
}

/*******************************************************************************
 Name:              ~View
 Description:       Deconstructor for View class
 ******************************************************************************/
View::~View()
{
    
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator for View class
 
 Input:
    other           const View&
 ******************************************************************************/
View View::operator=(const View& other)
{
    if(&other != this)
    {
        
    }
    
    return *this;
}

/*******************************************************************************
 Name:              update
 Description:       This method updates the screen
 ******************************************************************************/
void View::update()
{
    
}
