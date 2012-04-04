/*******************************************************************************
 Filename:                  Object.cpp
 Classname:                 Object

 Description:               This file defines the Object class.
 ******************************************************************************/
#include "Object.h"

/*******************************************************************************
 Name:              Object
 Description:       Default constructor for Object class
 ******************************************************************************/

Object::Object(int x, int y, int w, int h)
{
    pos.x = x;
    pos.y = y;
    pos.w = w;
    pos.h = h;

    drawable = physical = mechanical = false;
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other)
{
    pos = other.pos;
}

/*******************************************************************************
 Name:              ~Object
 Description:       Destructor for Object class
 ******************************************************************************/
Object::~Object()
{
    SDL_FreeSurface(image);
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
        pos = other.pos;
    }

    return *this;
}

vect Object::getVect()
{
    return vec;
}

/*******************************************************************************
 MUTATORS
 Name:              setType, setPos
 ******************************************************************************/
void Object::setPos(SDL_Rect p)
{
    pos = p;
}

void Object::setVect(vect v)
{
    vec = v;
}

/*******************************************************************************
 ACCESSORS
 Name:              getType, getPos
 ******************************************************************************/
SDL_Rect Object::getPos()
{
    return pos;
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

/*******************************************************************************
<<<<<<< HEAD
 Name:              draw
 Description:       Draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void Object::draw(SDL_Surface* s)
{
    SDL_BlitSurface(image, &pos, s, &pos);
}

void Object::update(SDL_Event event)
{
    if( event.type == SDL_MOUSEMOTION && grabbed)
    {
        pos.x = event.motion.x;
        pos.y = event.motion.y;
    }

    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            pos.x = event.button.x;
            pos.y = event.button.y;

            vec.xvel = 0;
            vec.yvel = 0;

            grabbed = true;

        }
    }

    if( event.type == SDL_MOUSEBUTTONUP )
    {
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            pos.x = event.button.x;
            pos.y = event.button.y;

            vec.xvel = 1;
            vec.yvel = 1;

            grabbed = false;
        }
    }

}
