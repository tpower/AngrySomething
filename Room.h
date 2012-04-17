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

class Room
{
    private:
        vector<Object*> object;

public:
        Object*             getObjectAt(int);
        int                 getNumObjects();

        bool                load(const char* f);
        void                add(Object*);
        void                remove(int i);
        void                erase();

};

#endif
