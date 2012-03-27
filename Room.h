/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room

 Description:               This file declares the Room class. The Room class
                            acts as the model for the Game. It holds state for
                            the game, holds the objects currently in the game,
                            and handles saving and loading the game.
 ******************************************************************************/

#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h

#include <string>
#include <fstream>
#include <vector>
#include "Base.h"
#include "DrawableObject.h"

class Object;

using namespace std;

class Room : public Base
{
    private:
        vector<DrawableObject*>      object;
        int                         numObjects;

    public:
        Room();

        DrawableObject*     getObjectAt(int);
        int         getNumObjects();

        bool        load();
};

#endif
