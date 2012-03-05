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

class Base
{
    private:
        static int  idGen;
        int         id;
        string      type;
        int         state;
        
    public:
        Base();
        Base(string);
        Base(const Base&);
        ~Base();
        Base operator=(const Base& other);
    
        void setState(int s);
    
        int     getID();
        string  getType();
        int     getState();
};

#endif
