/*******************************************************************************
 Filename:                  GraphicsEngine.cpp
 Classname:                 GraphicsEngine

 Description:               This file defines the GraphicsEngine class. The
                            GraphicsEngine class is responsible for output to
                            the screen.
 ******************************************************************************/

#include "GraphicsEngine.h"
#include "DrawableObject.h"
#include "Room.h"

/*******************************************************************************
 Name:              GraphicsEngine
 Description:       Default constructor for GraphicsEngine class
 ******************************************************************************/
GraphicsEngine::GraphicsEngine()
{
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);

    if(!screen)
    {
        exit(-1);
    }

    background = SDL_LoadBMP("background.bmp");
}

/*******************************************************************************
 Name:              ~GraphicsEngine
 Description:       Deconstructor for GraphicsEngine class
 ******************************************************************************/
GraphicsEngine::~GraphicsEngine()
{
    SDL_FreeSurface(screen);
    SDL_FreeSurface(background);
}

/*******************************************************************************
 Name:              run
 Description:       This method updates the screen
 ******************************************************************************/
void GraphicsEngine::run(Room& room)
{
    vector<DrawableObject*> temp;
    for(int i = 0; i < room.getNumObjects(); i++)
    {
        Object* obj = room.getObjectAt(i);

        if(obj->isDrawable())
            temp.push_back(dynamic_cast<DrawableObject*>(obj));
    }

    sortByLayer(temp);

    SDL_BlitSurface(background, NULL, screen, NULL);
    for(int i = 0; i < temp.size(); i++)
    {
        temp[i]->draw(screen);
    }

    SDL_Flip(screen);
    SDL_BlitSurface(background, NULL, screen, NULL);
}

void GraphicsEngine::sortByLayer(vector<DrawableObject*>& list)
{
    for(int i = 0; i < list.size(); i++)
    {
        for(int j = 0; j < list.size() - 1; j++)
        {
            if(list[j]->getLayer() >  list[j+1]->getLayer())
            {
                DrawableObject* temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
