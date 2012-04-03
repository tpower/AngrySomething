/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room

 Description:               This file declares the Room class.
 ******************************************************************************/
#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h
#include <vector>
#include "Object.h"

using namespace std;

class Room
{
    private:
        vector<Object*> object;

    public:
        Room();
        Room(const Room&);
        ~Room();

        Room                operator=(const Room& other);

        Object*             getObjectAt(int);
        int                 getNumObjects();

        bool                load();

};

#endif
