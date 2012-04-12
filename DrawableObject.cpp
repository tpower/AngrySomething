/*******************************************************************************
 Filename:                  DrawableObject.cpp
 Classname:                 DrawableObject

 Description:               This file defines the DrawableObject class.
 ******************************************************************************/

#include <iostream>

#include "DrawableObject.h"

using namespace std;

/*******************************************************************************
 Name:              DrawableObject
 Description:       Primary constructor
 ******************************************************************************/
DrawableObject::DrawableObject(const char* file)
{
    drawable = true;

    image = SDL_LoadBMP(file);

    if(!image)
    {
        cout << SDL_GetError() << endl;
    }

    Uint32 colorkey = SDL_MapRGB( image->format, 0xFF, 0xFF, 0xFF );
    SDL_SetColorKey( image, SDL_SRCCOLORKEY, colorkey );
}

/*******************************************************************************
 Name:              DrawableObject
 Description:       Copy constructor

 Input:
    other           DrawableObject& to be copied
 ******************************************************************************/
DrawableObject::DrawableObject(const DrawableObject& other)
{
    *image = *(other.image);
}

/*******************************************************************************
 Name:              ~DrawableObject
 Description:       Destructor
 ******************************************************************************/
DrawableObject::~DrawableObject()
{
    SDL_FreeSurface(image);
}

/*******************************************************************************
 Name:              operator=
 Description:       Overloaded assignment operator

 Input:
    other           DrawableObject& to be copied
 ******************************************************************************/
DrawableObject& DrawableObject::operator=(const DrawableObject& other)
{
    if(&other != this)
    {
        *image = *(other.image);
    }

    return *this;
}

/*******************************************************************************
 Name:              draw
 Description:       Draws the Object to the given SDL_Surface*

 Input:
    s               SDL_Surface* to be drawn onto
 ******************************************************************************/
void DrawableObject::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    SDL_BlitSurface(image, &pos, s, &loc);
}
