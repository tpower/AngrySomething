/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room

 Description:               This file declares the Room class.
 ******************************************************************************/

#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h

#include <vector>
#include <fstream>
#include <string>

class Object;

using namespace std;

enum {Level = 1, Utility = 2};

class Room
{
    private:
        vector<Object*> object;
        int roomType;

    public:
        Room();

        Room                operator=(const Room& other);

        Object*             getObjectAt(int);
        int                 getNumObjects();

        bool                load(const char* f);
        void                add(Object*);
        void                remove(int i);
        void                erase();
        void                setRoomType(int r) {roomType = r;}
        int                 getRoomType() {return roomType;}
};

#endif
