/*******************************************************************************
 Filename:                  Room.h
 Classname:                 Room

 Description:               The Room class is a container for objects in the
                            game and handles loading levels from files.
 ******************************************************************************/

#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h

#include <SDL/SDL.h>
#include <vector>
#include <fstream>
#include <string>

class Object;

using namespace std;

enum {Level = 1, Utility = 2};

class Room
{
    private:
        vector<Object*>     object;
        int                 roomType;
        SDL_Surface*        background;

    public:
        Room();
        ~Room();

        Room                operator=(const Room& other);

        Object*             getObjectAt(int);
        int                 getNumObjects();

        bool                load(const char* f);
        void                add(Object*);
        void                remove(int i);
        void                erase();
        void                setRoomType(int r) {roomType = r;}
        int                 getRoomType() {return roomType;}
        void                setBackground(const char* file);
        SDL_Surface*        getBackground();
        bool                pause();
        bool                unpause();
};

#endif
