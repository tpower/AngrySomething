/*******************************************************************************
 Filename:                  ConversationBox.h
 Classname:                 ConversationBox
 
 Description:               
 ******************************************************************************/

#include "ConversationBox.h"

ConversationBox::ConversationBox(int x, int y, string c)
    :   Object(x, y, 100, 200),
        DrawableObject("MonkeyConvBox.bmp", 10),
        MechanicsObject()
{
    conv = c;
    dispTime = 0;
    index = 0;

    type = 1;

    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = false;

    startTime = SDL_GetTicks();
}

Object* ConversationBox::process()
{
    if( !(index >= conv.length() + 2) && SDL_GetTicks() - startTime > dispTime*1000)
    {
        person = conv[index];
        dispTime = conv[index+1] - '0';
        index += 2;
        startTime = SDL_GetTicks();

        switch(person)
        {
            case 'M':
                image = SDL_LoadBMP("MonkeyConvBox.bmp");
                break;
            case 'W':
                image = SDL_LoadBMP("WolfConvBox.bmp");
                break;
        }
    }
    else if(index >= conv.length() + 2)
    {
        state = -1;
    }
    return NULL;
}

void ConversationBox::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    Uint32 colorkey = SDL_MapRGB( image->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey( image, SDL_SRCCOLORKEY, colorkey );

    SDL_BlitSurface(image, NULL, s, &loc);
}

void ConversationBox::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

void ConversationBox::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = false;
}