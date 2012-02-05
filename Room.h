
#ifndef AngrySomething_Room_h
#define AngrySomething_Room_h

#include <string>

#include "Base.h"
#include "Object.h"

using namespace std;

// Game Model
class Room : public Base
{
    private:
        Object* arr;
        
    public:
        Room();
        Room(const Room&);
        ~Room();
        
        // Load all of the objects from room file
        void load(string);
        
        // updates all of the objects
        void update();
};

#endif
