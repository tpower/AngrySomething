/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room
 
 Description:               This file declares the Room class. The Room class
                            acts as the model for the Game. It holds state for
                            the game, holds the objects currently in the game,
                            and handles saving and loading the game.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h

#include "Base.h"
#include "Object.h"
#include <string>
#include <fstream>

using namespace std;

class Room : public Base
{
    private:
        Object  *object;
        int     numObjects;
        
    public:
        Room();
        Room(const Room&);
        ~Room();
    
        Room operator=(const Room& other);
    
        Object& getObjectAt(int);
        int     getNumObjects();
    
        bool    load(fstream& file);
        bool    save(fstream& file);
        int     update();
};

#endif
