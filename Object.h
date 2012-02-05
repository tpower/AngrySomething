
#ifndef AngrySomething_Object_h
#define AngrySomething_Object_h

#include <string>

#include "Base.h"
#include "Component.h"

using namespace std;

// Object template
class Object : public Base
{
    private:
        Component *arr;
    public:
        Object();
        Object(Object&);
        ~Object();
        
        // Loads all of the components from object
        void loadAllComponent(string);
        
        // updates all the components
        void update();
};

#endif
