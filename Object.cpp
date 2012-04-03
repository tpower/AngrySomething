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
Object::Object(const char* file, int x, int y)
{
    type = OBJECT;

    pos.x = x;
    pos.y = y;
    pos.w = 60;
    pos.h = 60;

    vec.xvel = 1;
    vec.yvel = 1;

    grabbed = false;

    image = SDL_LoadBMP(file);

    if(!image)
    {
        cout << SDL_GetError() << endl;
    }
}

/*******************************************************************************
 Name:              Object
 Description:       Copy constructor for Object class
 ******************************************************************************/
Object::Object(const Object& other)
{
    type    = other.type;
    pos     = other.pos;
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
        type    = other.type;
        pos     = other.pos;
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
void Object::setType(ObjType t)
{
    type = t;
}

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
ObjType Object::getType()
{
    return type;
}

SDL_Rect Object::getPos()
{
    return pos;
}

/*******************************************************************************
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

void Object::move()
{
    pos.x += vec.xvel;
    pos.y += vec.yvel;
}
