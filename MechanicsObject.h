
#ifndef AngrySomething_MechanicsObject_h
#define AngrySomething_MechanicsObject_h

#include <SDL/SDL.h>

#include "Object.h"

class MechanicsObject : virtual public Object
{
    private:
        static int score;
    
    public:
        MechanicsObject();
        virtual Object* process();
    
        int getScore();
        void adjustScore(int);
};

#endif
