/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room

 Description:               This file declares the Room class.
 ******************************************************************************/

#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h

#include <vector>

class DrawableObject;

using namespace std;

class Room
{
    private:
        vector<DrawableObject*>      object;

    public:
        Room();
        Room(const Room&);
        ~Room();

        Room                operator=(const Room& other);

        DrawableObject*     getObjectAt(int);
        int                 getNumObjects();

        bool                load();

};

#endif
