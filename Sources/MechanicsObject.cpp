/*******************************************************************************
 Filename:                  MechanicsObject.h
 Classname:                 MechanicsObject
 
 Description:               The MechanicsObject class is a subclass of Object
                            that has game mechanics features.
 ******************************************************************************/

#include "MechanicsObject.h"

int MechanicsObject::score = 0;

/*******************************************************************************
 Name:              MechanicsObject
 Description:       Default constructor
 ******************************************************************************/
MechanicsObject::MechanicsObject()
{
    mechanical  = true;
}

/*******************************************************************************
 Name:              process
 Description:       This method processes any game mechanics of the
                    MechanicsObject
 
 Output:
    returns         Object* to be added to the room
 ******************************************************************************/
Object* MechanicsObject::process()
{
    return NULL;
}

/*******************************************************************************
 ACCESSORS
 Name:              getScore
 ******************************************************************************/
int MechanicsObject::getScore()
{
    return score;
}

/*******************************************************************************
 MODIFIERS
 Name:              adjustScore, resetScore
 ******************************************************************************/
void MechanicsObject::adjustScore(int x)
{
    score += x;
}

void MechanicsObject::resetScore()
{
    score = 0;
}

