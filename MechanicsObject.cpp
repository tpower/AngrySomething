
#include "MechanicsObject.h"

MechanicsObject::MechanicsObject()
{
    mechanical = true;
    grabbed = false;
}

Object* MechanicsObject::handle(SDL_Event e)
{
//    int static centerX = pos.x;
//    int static centerY = pos.y;

    if(e.type == SDL_MOUSEMOTION && grabbed)
    {

    }

    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {

        }
    }

    if(e.type == SDL_MOUSEBUTTONUP)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {

        }
    }

    return NULL;
}

int MechanicsObject::handleU(SDL_Event e)
{
    return NULL;
}
