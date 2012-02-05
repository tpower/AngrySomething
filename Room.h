/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room
 
 Description:               This file declares the Room class. The Room class
                            acts as the model for the Game. It holds state for
                            the game, holds the objects currently in the game,
                            and handles saving and loading the game.
 
 Last Modified:            				02.04.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h

#include <string>

#include "Base.h"
#include "Object.h"

using namespace std;

class Room : public Base
{
    private:
        Object* object;
        
    public:
        Room();
        Room(const Room&);
        ~Room();
        
        bool load(string);
        void update();
};

#endif
