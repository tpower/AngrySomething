/*******************************************************************************
 Filename:                  Object.h
 Classname:                 Object
 
 Description:               The Object class is the base class for objects
                            within the game environment.
 ******************************************************************************/

#include "Object.h"

/*******************************************************************************
 Name:              Object
 Description:       Primary constructor
 
 Input:
    x               int horizontal position
    y               int vertical position
    w               int width
    h               int height
 ******************************************************************************/
Object::Object(int x, int y, int w, int h)
{
    pos.x = x;
    pos.y = y;

    pos.w = w;
    pos.h = h;

    drawable = physical = mechanical = controllable = audible = false;

    state = 0;
    type = 0;
}

/*******************************************************************************
 Name:              ~Object
 Description:       Destructor
 ******************************************************************************/
Object::~Object()
{

}

/*******************************************************************************
 MUTATORS
 Name:              setPos
 ******************************************************************************/
void Object::setPos(SDL_Rect p)
{
    pos = p;
}

/*******************************************************************************
 ACCESSORS
 Name:              getPos, getState, getType, isDrawable, isPhysical,
                    isMechanical, isControllable, isAudible, check
 ******************************************************************************/
SDL_Rect Object::getPos()
{
    return pos;
}

int Object::getState()
{
    return state;
}

int Object::getType()
{
    return type;
}

bool Object::isDrawable()
{
    return drawable;
}

bool Object::isPhysical()
{
    return physical;
}

bool Object::isMechanical()
{
    return mechanical;
}

bool Object::isControllable()
{
    return controllable;
}

bool Object::isAudible()
{
    return audible;
}

int Object::check()
{
    return 0;
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the Object
 ******************************************************************************/
void Object::pause()
{

}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the NonInteractionObject if it is paused
 ******************************************************************************/
void Object::unpause()
{

}
