/*******************************************************************************
 Filename:                  ConversationBox.h
 Classname:                 ConversationBox
 ******************************************************************************/

#include "ConversationBox.h"

/*******************************************************************************
 Name:              ConversationBox
 Description:       Primary constructor
 
 Input:
    x               int horizontal position
    y               int vertical position
    c               string to be assigned to conv
 ******************************************************************************/
ConversationBox::ConversationBox(int x, int y, string c)
    :   Object(x, y, 100, 200),
        DrawableObject("Assets/Art/IntroCutscene/ConversationMonkey1.bmp", 10),
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


/*******************************************************************************
 Name:              process
 Description:       This method overrides MechanicsObject::process()
 
 Output:
    returns         Object*
 ******************************************************************************/
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
            case '1':
                image = SDL_LoadBMP("Assets/Art/IntroCutscene/ConversationMonkey1.bmp");
                break;
            case '2':
                image = SDL_LoadBMP("Assets/Art/IntroCutscene/ConversationMonkey2.bmp");
                break;
            case '3':
                image = SDL_LoadBMP("Assets/Art/IntroCutscene/ConversationMonkey3.bmp");
                break;
            case '4':
                image = SDL_LoadBMP("Assets/Art/IntroCutscene/ConversationMonkey4.bmp");
                break;
        }
    }
    else if(index >= conv.length() + 2)
    {
        state = -1;
    }
    return NULL;
}

/*******************************************************************************
 Name:              draw
 Description:       This method overrides DrawableObject::draw()
 
 Input:
    s               SDL_Surface* to be drawn to
 ******************************************************************************/
void ConversationBox::draw(SDL_Surface* s)
{
    static SDL_Rect loc;
    loc = pos;

    Uint32 colorkey = SDL_MapRGB( image->format, 0xFF, 0xAE, 0xC9);
    SDL_SetColorKey( image, SDL_SRCCOLORKEY, colorkey );

    SDL_BlitSurface(image, NULL, s, &loc);
}

/*******************************************************************************
 Name:              pause
 Description:       This method temporarily disables the ConversationBox
 ******************************************************************************/
void ConversationBox::pause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = false;
    activeCont = false;
}

/*******************************************************************************
 Name:              unpause
 Description:       This method enables the ConversationBox if it is paused
 ******************************************************************************/
void ConversationBox::unpause()
{
    activeDraw = true;
    activePhys = false;
    activeMech = true;
    activeCont = false;
}
