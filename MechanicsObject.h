/*******************************************************************************
 Filename:                  MechanicsObject.h
 Classname:                 MechanicsObject
 
 Description:               The MechanicsObject class is a subclass of Object
                            that has game mechanics features.
 ******************************************************************************/

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
        static void resetScore();
};

#endif
