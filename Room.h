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

#include "Base.h"

class Object;

using namespace std;

class Room : public Base
{
    private:
        Object      *object;
        int         numObjects;

    public:
        Room();
        Room(const Room&);
        ~Room();

        Room        operator=(const Room& other);

        Object&     getObjectAt(int);
        int         getNumObjects();

        void        removeObjectAt(int);

        bool        load(fstream& file);
        bool        save(fstream& file);
        GameState   update();
};

#endif
