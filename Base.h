/*******************************************************************************
 Filename:                  Base.h
 Classname:                 Base
 
 Description:               This file declares the Base class. The Base class
                            serves as the template for all classes.
 
 Last Modified:            				02.28.12
 By:									Tyler Orr
 - File created
 ******************************************************************************/

#ifndef AngrySomething_Base_h
#define AngrySomething_Base_h

#include <string>

using namespace std;

enum type
{
    BASE        = 0,
    GAME        = 1,
    VIEW        = 2,
    ROOM        = 3,
    OBJECT      = 4,
    MECHCOMP    = 5,
    GRPHCOMP    = 6,
    TRANCOMP    = 7,
    PHYSCOMP    = 8
};

class Base
{
    private:
        static int  idGen;
        int         id;
        int         type;
        int         state;
        
    public:
        Base();
        Base(int);
        Base(const Base&);
        ~Base();
        Base operator=(const Base& other);
    
        void setState(int s);
    
        int     getID() const;
        int     getType() const;
        int     getState() const;
};

#endif
