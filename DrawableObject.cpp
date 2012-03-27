#include "DrawableObject.h"
#include <iostream>

DrawableObject::DrawableObject(const char* file, int x, int y) : Object(x, y)
{
    image = SDL_LoadBMP(file);

    if(!image)
    {
        cout << SDL_GetError() << endl;
    }
}

void DrawableObject::draw(SDL_Surface* screen)
{
    SDL_BlitSurface(image, &position, screen, &position);

//    SDL_Delay(200);
}
