/*******************************************************************************
 Filename:                  GraphicsEngine.h
 Classname:                 GraphicsEngine
 
 Description:               The GraphicsEngine class handles drawing objects to
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
}

/*******************************************************************************
 Name:              ~GraphicsEngine
 Description:       Deconstructor for GraphicsEngine class
 ******************************************************************************/
GraphicsEngine::~GraphicsEngine()
{
    SDL_FreeSurface(screen);
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

        if(obj->isDrawable() && obj->getActiveDraw())
            temp.push_back(dynamic_cast<DrawableObject*>(obj));
    }

    sortByLayer(temp);


    for(int i = 0; i < temp.size(); i++)
    {
        temp[i]->draw(screen);
    }

    SDL_Flip(screen);
    SDL_BlitSurface(room.getBackground(), NULL, screen, NULL);
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
