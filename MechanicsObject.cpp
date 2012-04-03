
#include "MechanicsObject.h"

void MechanicsObject::handle(SDL_Event e)
{
    if(e.type == SDL_MOUSEMOTION && grabbed)
    {
        pos.x = e.motion.x;
        pos.y = e.motion.y;
    }
    
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            pos.x = e.button.x;
            pos.y = e.button.y;
            
            grabbed = true;
        }
    }
    
    if(e.type == SDL_MOUSEBUTTONUP)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            pos.x = e.button.x;
            pos.y = e.button.y;
            
            grabbed = false;
        }
    }
}
