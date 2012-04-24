/*******************************************************************************
 Filename:                  MechanicsObject.h
 Classname:                 MechanicsObject
 
 Description:               The MechanicsObject class is a subclass of Object
                            that has game mechanics features.
 ******************************************************************************/

#include "MechanicsObject.h"

int MechanicsObject::score = 0;

MechanicsObject::MechanicsObject()
{
    mechanical  = true;
}

Object* MechanicsObject::process()
{
    return NULL;
}

int MechanicsObject::getScore()
{
    return score;
}

void MechanicsObject::adjustScore(int x)
{
    score += x;
}

void MechanicsObject::resetScore()
{
    score = 0;
}